#include "Search.h"
#include "Evaluation.h"

Search::Search(MoveGen& mg)
	:move_generator(mg), best_move(13, 13, null_piece, 0, false, ' ', 0, 0)
{
	root = 0;
}

double Search::alphaBeta(BoardRepresentation& board_representation, int depth, int root_distance, double alpha, double beta)
{

	//CHECK FOR DRAWS

	if (board_representation.dead_position() || is_threefold(board_representation) || board_representation.get_halfmove() > 100)  return VALUE_DRAW;

	if (depth <= 0) return quiescence(board_representation, alpha, beta);

	//CHECK TRANSPOSITION TABLE

	auto tt_entry = main_TT->get(ZobristHashing::hash_position(board_representation));

	if (tt_entry.depth >= depth) {

		return tt_entry.eval;

	}

	//MATE DISTANCE PRUNING

	alpha = std::max(mated_score(board_representation, root_distance), alpha) - 1;
	beta = std::min(mate_score(board_representation, root_distance), beta) + 1;

	if (alpha >= beta) return alpha; 


	//NULL MOVE PRUNING

	double static_eval = Evaluation::material_eval(board_representation);

	
	int R = 3;

	if (allowed_null(board_representation, alpha, beta) && static_eval > beta && depth > (R + 1)) {

		move_generator.make_nullmove(board_representation);

		double eval = -alphaBeta(board_representation, depth - R - 1, root_distance + 1, -beta, -alpha);

		move_generator.unmake_nullmove(board_representation);

		if (eval >= beta) return beta;
	}
	
	
	// -------------------------------------------------------------//

	double max_eval = std::numeric_limits<int>::min();

	move_generator.generate_pseudo_legal_moves(board_representation); 

	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = test_sort(board_representation, move_generator.get_legal_move_list(), depth);

	//std::vector<Move> moves = sort_moves(move_generator.get_legal_move_list());


	for (const auto& move : moves) {

		move_generator.make_move(board_representation, move);

		double eval = -alphaBeta(board_representation, depth - 1, root_distance + 1, -beta, -alpha);

		max_eval = std::max(max_eval, eval);

		move_generator.un_make_move(board_representation, move);

		if (eval > alpha) {
			alpha = eval;

			best_move = move;

			if (beta > eval) {
				//hash_tt->put(ZobristHashing::hash_position(board_representation), move, depth, eval, PV_NODE);
				pv_TT->put(ZobristHashing::hash_position(board_representation), move, depth, eval, PV_NODE);
			}

		}
		if (alpha >= beta) return alpha;

		main_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, max_eval, PV_NODE);

	}

	//CHECKMATE OR STALEMATE
	if (moves.size() == 0) {
		max_eval = check_or_stale(board_representation, depth);
	}


	return max_eval;
}

double Search::PVS(BoardRepresentation& board_representation, int depth, int root_distance, double alpha, double beta, int pred_node) 
{

	//CHECK FOR DRAWS

	if (board_representation.dead_position() || is_threefold(board_representation) || board_representation.get_halfmove() > 100)  return VALUE_DRAW;


	//EXTEND SEARCH IF IN CHECK

	if (in_check(board_representation)) depth += 1;


	//HOP INTO QUIESCENCE SEARCH

	if (depth <= 0) return quiescence(board_representation, alpha, beta);


	//CHECK TRANSPOSITION TABLE

	
	/*
	if (pred_node == NON_PV) {

		auto tt_entry = main_TT->get(ZobristHashing::hash_position(board_representation));

		if (tt_entry.depth >= depth) {

			return tt_entry.eval;
		}
	}
	*/
	

	//MATE DISTANCE PRUNING

	//alpha = std::max(mated_score(board_representation, root_distance), alpha) + 1;
	//beta = std::min(mate_score(board_representation, root_distance), beta) - 1;
	
	//if (alpha >= beta) return alpha;


	//INITIALIZE SEARCH VARIABLES

	double best_score = std::numeric_limits<int>::min();
	int depth_reduction = depth;
	double eval = 0;
	bool current_check = in_check(board_representation);
	bool first_move = true;
	double static_eval = Evaluation::material_eval(board_representation);


	
	//REVERSE FUTILITY PRUNING

	if (pred_node == NON_PV && !current_check) {

		if ((depth == 1 && static_eval >= beta + FUTILITY_MARGIN) ||
			(depth == 2 && static_eval >= beta + EXTENDED_FMARGIN)) return static_eval;

	}

	
	//NULL MOVE PRUNING

	int R = 3;

	if (pred_node == NON_PV && allowed_null(board_representation, alpha, beta) && static_eval > beta && depth > (R + 1)) {

		move_generator.make_nullmove(board_representation);

		double eval = -PVS(board_representation, depth - R - 1, root_distance + 1, -beta, -alpha, NON_PV);

		move_generator.unmake_nullmove(board_representation);

		if (eval >= beta) return beta;
	}

	
	
	//LIMITED RAZORING

	if (pred_node == NON_PV && board_representation.material_total <= 360 && !current_check) {

		if (static_eval + RAZOR_MARGIN <= alpha)

			depth_reduction--;

	}

	

	move_generator.generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = test_sort(board_representation, move_generator.get_legal_move_list(), depth);

	//std::vector<Move> moves = sort_moves(move_generator.get_legal_move_list());

	for (const auto& move : moves) {


		// FIRST MOVE

		if (first_move) {

			first_move = false;

			move_generator.make_move(board_representation, move);

			++scounter;

			best_score = -PVS(board_representation, depth - 1, root_distance + 1, -beta, -alpha, PV_NODE);

			move_generator.un_make_move(board_representation, move);

			if (best_score > alpha) {

				best_move = move;

				if (root_distance == 0) engine_move = move;

				if (best_score >= beta) {

					pv_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, best_score, EXACT_BOUND);

					main_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, best_score, LOWER_BOUND);
				
					return best_score;
				}

				alpha = best_score;
			}

			pv_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, best_score, EXACT_BOUND);

			main_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, best_score, EXACT_BOUND);

		}

		// REMAINING MOVES

		else {

			move_generator.make_move(board_representation, move);


			// FUTILITY PRUNING

				

			if (!current_check) {

				if (allowed_futility(board_representation, depth, move) && (alpha < VALUE_MATE && beta > VALUE_MATED)) {

					if (static_eval + FUTILITY_MARGIN <= alpha) {

						move_generator.un_make_move(board_representation, move);

						continue;
					}
				}
			}

			
			 
			// LATE MOVE REDUCTION

			
			if (!current_check) {

				if (allowed_lmr(board_representation, depth, move)) {

					int R = 1;

					depth_reduction = depth - R;

				}
			}

			
			++scounter;

			eval = -PVS(board_representation, depth_reduction - 1, root_distance + 1, -alpha - 1, -alpha, NON_PV);

			if (eval > alpha && eval < beta) {

				++scounter;

				eval = -PVS(board_representation, depth - 1, root_distance + 1, -beta, -alpha, PV_NODE);

			}

			move_generator.un_make_move(board_representation, move);


			if (eval > best_score) {

				best_score = eval;

				if (eval > alpha) {

					best_move = move;

					if (root_distance == 0) engine_move = move;

					if (eval >= beta) {

						if (!(move.capture > 0 || move.promotion > 0)) {

							add_killers(move, depth);

						}

						main_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, eval, LOWER_BOUND);

						return eval;
					}

					alpha = eval;
					pv_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, eval, LOWER_BOUND);
				}
			}
		}

		main_TT->put(ZobristHashing::hash_position(board_representation), best_move, depth, best_score, EXACT_BOUND);

	}

	//CHECKMATE OR STALEMATE
	if (moves.size() == 0) {
		best_score = check_or_stale(board_representation, depth);
	}

	//hash_tt->put(ZobristHashing::hash_position(board_representation), best_move, depth, eval, NON_PV);

	return best_score;
}


void Search::search_init()
{
	pv_TT = new TranspositionTable(256);
	main_TT = new TranspositionTable(256);

}

void Search::reset()
{
	pv_TT->clear_TT();
	main_TT->clear_TT();

	//std::memset(pv_TT, 0, 1024 * 1024 * 256);
	//std::memset(main_TT, 0, 1024 * 1024 * 256);

}

void Search::search(BoardRepresentation& board_representation)
{

	double eval;

	//search_init();

	//std::cout << ZobristHashing::hash_position(board_representation);

	// ITERATIVE DEEPENING

	for (int depth = 1; depth < 9; ++depth) {

		//std::cout << std::endl;
		//std::cout << "depth: " << depth << std::endl;
		//std::cout << std::endl;

	eval = PVS(board_representation, depth, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), PV_NODE);
	//eval = alphaBeta(board_representation, depth, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	nodecounter += (scounter + qcounter);
	scounter, qcounter = 0;

	pv = pv_TT->extract_pv(board_representation, depth);

	std::cout << "info score cp " << eval * 100 << " depth " << depth << " nodes " << scounter + qcounter << " time " << 0 << " pv ";
	print_pv(pv);
	std::cout << std::endl;

	}

	std::cout << std::endl;


}


double Search::quiescence(BoardRepresentation& board_representation, double alpha, double beta)
{


	double stand_pat = Evaluation::material_eval(board_representation);

	if (stand_pat >= beta) return beta;

	if (stand_pat > alpha) alpha = stand_pat;

	move_generator.generate_pseudo_legal_moves(board_representation);
	
	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = quiesence_sort(move_generator.get_legal_move_list());

	for (const auto& move : moves) {

		if (allowed_delta(board_representation)) {

			double piece_value = board_representation.value_convert[move.capture];

			if (stand_pat + piece_value + DELTA_MARGIN <= alpha) continue;
		}

		move_generator.make_move(board_representation, move);

		++qcounter;

		double eval = -quiescence(board_representation, -beta, -alpha);

		move_generator.un_make_move(board_representation, move);

		if (eval >= beta) {
			return beta;
		}

		if (eval > alpha) {
			alpha = eval;
		}
	}

	return alpha;

}



std::vector<Move> Search::sort_moves(std::vector<Move> moves)
{
	//MVV - LVA

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});

	return moves;
}

std::vector<Move> Search::quiesence_sort(std::vector<Move>& moves)
{


	/*moves.erase(
		std::remove_if(moves.begin(), moves.end(),
			[&](Move m)-> bool { return m.promotion > 0 || m.capture > 0; }),
		moves.end());

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});

	std::stable_partition(std::begin(moves),
		std::end(moves),
		[](const Move& m) { return m.promotion > 0; }
	);*/

	moves.erase(std::remove_if(moves.begin(), moves.end(), [](const Move& m) {return m.capture == 0;}), moves.end());

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});


	return moves;

}



std::vector<Move> Search::test_sort(const BoardRepresentation& board_representation, std::vector<Move>& moves, int depth) {

	//Move hash_move = main_TT->get(ZobristHashing::hash_position(board_representation)).move;
	Move hash_move = main_TT->get(board_representation.position_key).move;

	for (auto& move : moves) {

		int move_int = move.move_toInt();

		if (move_int == hash_move.move_toInt()) move.score = HASH_MOVE;

		else if (move.promotion > 0) move.score = PROMOTION_SCORE + move.promotion;

		else if (move_int == killer_moves[0][depth].move_toInt()) move.score = KILLER_ONE;

		else if (move_int == killer_moves[1][depth].move_toInt()) move.score = KILLER_TWO;

		else move.score = 15 * move.capture - move.piece_type;

	}

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.score > b.score;
		});

	return moves;
}

bool Search::allowed_null(BoardRepresentation& board_representation, double alpha, double beta) {

	int index;
	int attacking_color;

	if (board_representation.get_side()) {
		index = board_representation.white_king_square;
		attacking_color = black;
	}

	else {
		index = board_representation.black_king_square;
		attacking_color = white;
	}

	return (!(beta - alpha > 1) && !move_generator.is_attacked(board_representation, index, attacking_color));


}

double Search::mated_score(BoardRepresentation& board_representation, int remaining_depth)
{
	return VALUE_MATED + remaining_depth;

}

double Search::check_or_stale(BoardRepresentation& board_representation, int remaining_depth)
{
	//CHECKMATE
	if (in_check(board_representation)) return mated_score(board_representation, remaining_depth);

	//STALEMATE
	else return VALUE_DRAW;
}

double Search::mate_score(BoardRepresentation& board_representation, int remaining_depth)
{
	return VALUE_MATE - remaining_depth;
}

bool Search::is_threefold(const BoardRepresentation& board_representation)
{

	int repitition = 0;

	if (board_representation.get_halfmove() < 4) return false;

	auto zobrist = board_representation.position_key;

	for (int i = move_generator.get_main_info().size() - 2; i >= 0; i = i - 2) {

		if (move_generator.get_main_info()[i].last_key == zobrist) {
			++repitition;
		}	

		if (repitition == 2) return true;
	}

	return false;
}

void Search::add_killers(const Move& m, int depth)
{

	if (killer_moves[0][depth].move_toInt() == m.move_toInt()) killer_moves[1][depth] = m;

	else killer_moves[0][depth] = m;

}

void Search::print_pv(std::vector<Move> pv)
{

	for (const auto& move : pv) {

		std::cout << move_generator.for_print_movegen[move.start_index];
		std::cout << move_generator.for_print_movegen[move.end_index];
		std::cout << " ";
	}
}

bool Search::allowed_delta(const BoardRepresentation& board_representation)
{
	if (board_representation.material_total <= 360) return false;

	return true;
}

bool Search::allowed_futility(BoardRepresentation& board_representation, int depth, const Move & m)
{

	if (depth != 1) return false;

	if (m.capture > 0) return false;

	if (m.promotion > 0) return false; 

	if (in_check(board_representation)) return false; 
	
	return true;

}

bool Search::allowed_lmr(BoardRepresentation& board_representation, int depth, const Move& m) 
{

	if (depth < 3) return false;

	if (m.capture > 0) return false;

	if (m.promotion > 0) return false;

	if (in_check(board_representation)) return false;	 

	return true;


}


bool Search::in_check(BoardRepresentation& board_representation) {

	if (board_representation.get_side()) return move_generator.is_attacked(board_representation, board_representation.white_king_square, black);

	else return move_generator.is_attacked(board_representation, board_representation.black_king_square, white);

}