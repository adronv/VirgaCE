#include "MoveGen.h"

MoveGen::MoveGen() {


	for_print_movegen.insert(std::pair<int, std::string>(0, "a1"));
	for_print_movegen.insert(std::pair<int, std::string>(1, "b1"));
	for_print_movegen.insert(std::pair<int, std::string>(2, "c1"));
	for_print_movegen.insert(std::pair<int, std::string>(3, "d1"));
	for_print_movegen.insert(std::pair<int, std::string>(4, "e1"));
	for_print_movegen.insert(std::pair<int, std::string>(5, "f1"));
	for_print_movegen.insert(std::pair<int, std::string>(6, "g1"));
	for_print_movegen.insert(std::pair<int, std::string>(7, "h1"));
	for_print_movegen.insert(std::pair<int, std::string>(16, "a2"));
	for_print_movegen.insert(std::pair<int, std::string>(17, "b2"));
	for_print_movegen.insert(std::pair<int, std::string>(18, "c2"));
	for_print_movegen.insert(std::pair<int, std::string>(19, "d2"));
	for_print_movegen.insert(std::pair<int, std::string>(20, "e2"));
	for_print_movegen.insert(std::pair<int, std::string>(21, "f2"));
	for_print_movegen.insert(std::pair<int, std::string>(22, "g2"));
	for_print_movegen.insert(std::pair<int, std::string>(23, "h2"));
	for_print_movegen.insert(std::pair<int, std::string>(32, "a3"));
	for_print_movegen.insert(std::pair<int, std::string>(33, "b3"));
	for_print_movegen.insert(std::pair<int, std::string>(34, "c3"));
	for_print_movegen.insert(std::pair<int, std::string>(35, "d3"));
	for_print_movegen.insert(std::pair<int, std::string>(36, "e3"));
	for_print_movegen.insert(std::pair<int, std::string>(37, "f3"));
	for_print_movegen.insert(std::pair<int, std::string>(38, "g3"));
	for_print_movegen.insert(std::pair<int, std::string>(39, "h3"));
	for_print_movegen.insert(std::pair<int, std::string>(48, "a4"));
	for_print_movegen.insert(std::pair<int, std::string>(49, "b4"));
	for_print_movegen.insert(std::pair<int, std::string>(50, "c4"));
	for_print_movegen.insert(std::pair<int, std::string>(51, "d4"));
	for_print_movegen.insert(std::pair<int, std::string>(52, "e4"));
	for_print_movegen.insert(std::pair<int, std::string>(53, "f4"));
	for_print_movegen.insert(std::pair<int, std::string>(54, "g4"));
	for_print_movegen.insert(std::pair<int, std::string>(55, "h4"));
	for_print_movegen.insert(std::pair<int, std::string>(64, "a5"));
	for_print_movegen.insert(std::pair<int, std::string>(65, "b5"));
	for_print_movegen.insert(std::pair<int, std::string>(66, "c5"));
	for_print_movegen.insert(std::pair<int, std::string>(67, "d5"));
	for_print_movegen.insert(std::pair<int, std::string>(68, "e5"));
	for_print_movegen.insert(std::pair<int, std::string>(69, "f5"));
	for_print_movegen.insert(std::pair<int, std::string>(70, "g5"));
	for_print_movegen.insert(std::pair<int, std::string>(71, "h5"));
	for_print_movegen.insert(std::pair<int, std::string>(80, "a6"));
	for_print_movegen.insert(std::pair<int, std::string>(81, "b6"));
	for_print_movegen.insert(std::pair<int, std::string>(82, "c6"));
	for_print_movegen.insert(std::pair<int, std::string>(83, "d6"));
	for_print_movegen.insert(std::pair<int, std::string>(84, "e6"));
	for_print_movegen.insert(std::pair<int, std::string>(85, "f6"));
	for_print_movegen.insert(std::pair<int, std::string>(86, "g6"));
	for_print_movegen.insert(std::pair<int, std::string>(87, "h6"));
	for_print_movegen.insert(std::pair<int, std::string>(96, "a7"));
	for_print_movegen.insert(std::pair<int, std::string>(97, "b7"));
	for_print_movegen.insert(std::pair<int, std::string>(98, "c7"));
	for_print_movegen.insert(std::pair<int, std::string>(99, "d7"));
	for_print_movegen.insert(std::pair<int, std::string>(100, "e7"));
	for_print_movegen.insert(std::pair<int, std::string>(101, "f7"));
	for_print_movegen.insert(std::pair<int, std::string>(102, "g7"));
	for_print_movegen.insert(std::pair<int, std::string>(103, "h7"));
	for_print_movegen.insert(std::pair<int, std::string>(112, "a8"));
	for_print_movegen.insert(std::pair<int, std::string>(113, "b8"));
	for_print_movegen.insert(std::pair<int, std::string>(114, "c8"));
	for_print_movegen.insert(std::pair<int, std::string>(115, "d8"));
	for_print_movegen.insert(std::pair<int, std::string>(116, "e8"));
	for_print_movegen.insert(std::pair<int, std::string>(117, "f8"));
	for_print_movegen.insert(std::pair<int, std::string>(118, "g8"));
	for_print_movegen.insert(std::pair<int, std::string>(119, "h8"));

	for_movegen.insert(std::pair<std::string, int>("a1", 0));
	for_movegen.insert(std::pair<std::string, int>("b1", 1));
	for_movegen.insert(std::pair<std::string, int>("c1", 2));
	for_movegen.insert(std::pair<std::string, int>("d1", 3));
	for_movegen.insert(std::pair<std::string, int>("e1", 4));
	for_movegen.insert(std::pair<std::string, int>("f1", 5));
	for_movegen.insert(std::pair<std::string, int>("g1", 6));
	for_movegen.insert(std::pair<std::string, int>("h1", 7));
	for_movegen.insert(std::pair<std::string, int>("a2", 16));
	for_movegen.insert(std::pair<std::string, int>("b2", 17));
	for_movegen.insert(std::pair<std::string, int>("c2", 18));
	for_movegen.insert(std::pair<std::string, int>("d2", 19));
	for_movegen.insert(std::pair<std::string, int>("e2", 20));
	for_movegen.insert(std::pair<std::string, int>("f2", 21));
	for_movegen.insert(std::pair<std::string, int>("g2", 22));
	for_movegen.insert(std::pair<std::string, int>("h2", 23));
	for_movegen.insert(std::pair<std::string, int>("a3", 32));
	for_movegen.insert(std::pair<std::string, int>("b3", 33));
	for_movegen.insert(std::pair<std::string, int>("c3", 34));
	for_movegen.insert(std::pair<std::string, int>("d3", 35));
	for_movegen.insert(std::pair<std::string, int>("e3", 36));
	for_movegen.insert(std::pair<std::string, int>("f3", 37));
	for_movegen.insert(std::pair<std::string, int>("g3", 38));
	for_movegen.insert(std::pair<std::string, int>("h3", 39));
	for_movegen.insert(std::pair<std::string, int>("a4", 48));
	for_movegen.insert(std::pair<std::string, int>("b4", 49));
	for_movegen.insert(std::pair<std::string, int>("c4", 50));
	for_movegen.insert(std::pair<std::string, int>("d4", 51));
	for_movegen.insert(std::pair<std::string, int>("e4", 52));
	for_movegen.insert(std::pair<std::string, int>("f4", 53));
	for_movegen.insert(std::pair<std::string, int>("g4", 54));
	for_movegen.insert(std::pair<std::string, int>("h4", 55));
	for_movegen.insert(std::pair<std::string, int>("a5", 64));
	for_movegen.insert(std::pair<std::string, int>("b5", 65));
	for_movegen.insert(std::pair<std::string, int>("c5", 66));
	for_movegen.insert(std::pair<std::string, int>("d5", 67));
	for_movegen.insert(std::pair<std::string, int>("e5", 68));
	for_movegen.insert(std::pair<std::string, int>("f5", 69));
	for_movegen.insert(std::pair<std::string, int>("g5", 70));
	for_movegen.insert(std::pair<std::string, int>("h5", 71));
	for_movegen.insert(std::pair<std::string, int>("a6", 80));
	for_movegen.insert(std::pair<std::string, int>("b6", 81));
	for_movegen.insert(std::pair<std::string, int>("c6", 82));
	for_movegen.insert(std::pair<std::string, int>("d6", 83));
	for_movegen.insert(std::pair<std::string, int>("e6", 84));
	for_movegen.insert(std::pair<std::string, int>("f6", 85));
	for_movegen.insert(std::pair<std::string, int>("g6", 86));
	for_movegen.insert(std::pair<std::string, int>("h6", 87));
	for_movegen.insert(std::pair<std::string, int>("a7", 96));
	for_movegen.insert(std::pair<std::string, int>("b7", 97));
	for_movegen.insert(std::pair<std::string, int>("c7", 98));
	for_movegen.insert(std::pair<std::string, int>("d7", 99));
	for_movegen.insert(std::pair<std::string, int>("e7", 100));
	for_movegen.insert(std::pair<std::string, int>("f7", 101));
	for_movegen.insert(std::pair<std::string, int>("g7", 102));
	for_movegen.insert(std::pair<std::string, int>("h7", 103));
	for_movegen.insert(std::pair<std::string, int>("a8", 112));
	for_movegen.insert(std::pair<std::string, int>("b8", 113));
	for_movegen.insert(std::pair<std::string, int>("c8", 114));
	for_movegen.insert(std::pair<std::string, int>("d8", 115));
	for_movegen.insert(std::pair<std::string, int>("e8", 116));
	for_movegen.insert(std::pair<std::string, int>("f8", 117));
	for_movegen.insert(std::pair<std::string, int>("g8", 118));
	for_movegen.insert(std::pair<std::string, int>("h8", 119));

	move_list.reserve(60);
	legal_move_list.reserve(60);

	made_moves.reserve(20);
	main_info.reserve(20);

}


void MoveGen::generate_pseudo_legal_moves(const BoardRepresentation& board_representation)
{
	move_list.clear();

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	//for (const auto& map_pair : board_representation.get_piece_list()) {
	for (int i = 0; i < 120; ++i) {

	if (i % 8 == 0 && i != 0 && i < 112) i = i + 8;

	//NEWNEW
	//for (int i : board_representation.get_piece_lists()) {

			int helper_two = 0;

			//int helper = map_pair.second & piece_color_check;

			if (board_arr[i] > 0) {
				helper_two = board_arr[i];


				int helper = helper_two & piece_color_check;

				if (((helper == white) && board_representation.get_side()) || ((helper == black) && !board_representation.get_side())) {

					switch (helper_two) {

					case (white_pawn):
					case (black_pawn): {

						generate_pl_pawn_moves(board_representation, i);
						break;

					}

					case(white_knight):
					case(black_knight): {

						generate_pl_leaping_moves(board_representation, i, knight_offset, leaping_array_size);
						break;

					}

					case(white_bishop):
					case(black_bishop): {

						int array_size = 4;
						generate_pl_sliding_moves(board_representation, i, bishop_offset, sliding_array_size);
						break;

					}

					case(white_rook):
					case(black_rook): {


						generate_pl_sliding_moves(board_representation, i, rook_offset, sliding_array_size);
						break;

					}

					case(white_king):
					case(black_king): {

						generate_pl_leaping_moves(board_representation, i, king_offset, leaping_array_size);
						generate_pl_castle_moves(board_representation, i);
						break;

					}

					case(white_queen):
					case(black_queen): {

						generate_pl_sliding_moves(board_representation, i, queen_offset, queen_array_size);
						break;

					}

					}

				}

				//NEEDTHIS}

			//new new
			}
	}

}

void MoveGen::generate_pl_pawn_moves(const BoardRepresentation& board_representation, int index)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	int promotion_helper = board_arr[index] & piece_color_check;
	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < pawn_array_size; ++i) {

		int offset = pawn_offset[i];
		int target_square = index + color * offset;


		if (board_representation.is_on_board(target_square)) {

			// PAWN MOVING FORWARD
			if (i == 0 && board_arr[target_square] == null_piece) {

				if (((index < a3 && color == 1) || (index > h6 && color == -1)) && board_arr[index + color * offset * 2] == null_piece) {

						move_list.push_back(Move(index, index + color * offset * 2, board_arr[index], null_piece, true, ' ', null_piece, 0));
						move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', null_piece, 0));

					
				}
				else if ((index <= h2 && color == -1) || (index >= a7 && color == 1)) {
					move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', neutral_knight + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', neutral_bishop + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', neutral_rook + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', neutral_queen + promotion_helper, 0));
					
				}

				else move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', null_piece, 0));
			}
			//PAWN CAPTURE	
			if (i != 0 && board_arr[target_square] != 0 && ((board_arr[index] & piece_color_check) & (board_arr[target_square] & piece_color_check)) == null_piece) {

				if ((index <= h2 && color == -1) || (index >= a7 && color == 1)) {
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', neutral_knight + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', neutral_bishop + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', neutral_rook + promotion_helper, 0));
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', neutral_queen + promotion_helper, 0));

				}
				else move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', null_piece, 0));

			}
			//ENPASSANT 
			if (i != 0 && target_square == board_representation.get_enpassant()) {

				if ((board_arr[index] & piece_color_check) == white && board_arr[target_square - 16] == black_pawn) {
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square - 16], true, ' ', null_piece, 0));
				}

				if ((board_arr[index] & piece_color_check) == black && board_arr[target_square + 16] == white_pawn) {
					move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square + 16], true, ' ', null_piece, 0));
				}

			}
				
		}

		
	}
}

void MoveGen::generate_pl_sliding_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	

	for (int i = 0; i < array_size ; ++i) {

		int target_square = index + piece_offset[i];

		while (board_representation.is_on_board(target_square)) {
				
			if (((board_arr[target_square] & board_arr[index]) & 0x03) == 0 && board_arr[target_square] > null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', null_piece, 0));

				break;

			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', null_piece, 0));

			else break;

			target_square += piece_offset[i];

		}


	}

}

void MoveGen::generate_pl_leaping_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size) {

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	
	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < array_size; ++i) {

		int target_square = index + color * piece_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (((board_arr[target_square] & board_arr[index]) & piece_color_check) == 0 && board_arr[target_square] > 0) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', null_piece, 0));
			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', null_piece, 0));

		}

	}

}

void MoveGen::generate_legal_moves(BoardRepresentation& board_representation, int color)
	{

	legal_move_list.clear();

	int king_index;

	int color_helper = white;

	if (color == white) color_helper = black;

	for (const auto& move : move_list) {

		make_move(board_representation, move);

		if (color == white) king_index = board_representation.white_king_square; else king_index = board_representation.black_king_square;

		if (move.castle != ' ') {
			make_castle(board_representation, move.castle);	
		}
		
		if (!(is_attacked(board_representation, king_index, color_helper))) {
			legal_move_list.push_back(move);
		}
		
		un_make_move(board_representation, move);

	}
}

void MoveGen::generate_pl_castle_moves(const BoardRepresentation& board_representation, int index)
{
	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	

	// WHITE CASTLING 

	if ((board_arr[index] & piece_color_check) == white) {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_arr[index + 3] == white_rook && board_representation.get_castling_rights().find('K') != std::string::npos) {
			if (!(is_attacked(board_representation, index, black) || is_attacked(board_representation, index + 1, black) || is_attacked(board_representation, index + 2, black))) {
				move_list.push_back(Move(index, index + 2, white_king, null_piece, false, 'K', null_piece, 0));
			}
		}

		//LONG CASTLE
		std::string y = board_representation.get_castling_rights();
		if (board_representation.get_castling_rights().find('Q')!= std::string::npos) {
			if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_arr[index - 4] == white_rook) {
				if (!(is_attacked(board_representation, index, black) || is_attacked(board_representation, index - 1, black) || is_attacked(board_representation, index - 2, black))) {
					move_list.push_back(Move(index, index - 2, white_king, null_piece, false, 'Q', null_piece, 0));
				}
			}
		}

	}

	// BLACK CASTLING 

	else {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_arr[index + 3] == black_rook && board_representation.get_castling_rights().find('k') != std::string::npos) {
			if (!(is_attacked(board_representation, index, white) || is_attacked(board_representation, index + 1, white) || is_attacked(board_representation, index + 2, white))) {
				move_list.push_back(Move(index, index + 2, black_king, null_piece, false, 'k', null_piece, 0));
			}
		}

		//LONG CASTLE

		if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_arr[index - 4] == black_rook && board_representation.get_castling_rights().find('q') != std::string::npos) {
			if (!(is_attacked(board_representation, index, white) || is_attacked(board_representation, index - 1, white) || is_attacked(board_representation, index - 2, white))) {
				move_list.push_back(Move(index, index - 2, black_king, null_piece, false, 'q', null_piece, 0));
			}
		}

	}

}


void MoveGen::make_move(BoardRepresentation& board_representation, Move m)
{

	if  (made_moves.size() > 0 && made_moves.back().enpassant && made_moves.back().capture == 0) {
		if (made_moves.back().piece_type == white_pawn) {
			board_representation.position_key ^= ZobristHashing::enpassant_keys[((made_moves.back().end_index - 16) & 7)];
		}
		else {
			board_representation.position_key ^= ZobristHashing::enpassant_keys[((made_moves.back().end_index + 16) & 7)];
		}
	}

	board_representation.set_halfmove(board_representation.get_halfmove() + 1);

	board_representation.set_enpassant(NULL_ENPASSANT);

	if (m.enpassant == true) {
		if (m.capture > 0) {

			if (m.piece_type == white_pawn) {
				board_representation.remove_piece(m.end_index - 16);
				board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[black_pawn]][m.end_index - 16];
			}
			else {
				board_representation.remove_piece(m.end_index + 16);
				board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[white_pawn]][m.end_index + 16];
			}
		}
		else {
			if (m.piece_type == white_pawn) {
				board_representation.set_enpassant(m.end_index - 16);
				board_representation.position_key ^= ZobristHashing::enpassant_keys[((m.end_index - 16) & 7)];
			}
			else {
				board_representation.set_enpassant(m.end_index + 16);
				board_representation.position_key ^= ZobristHashing::enpassant_keys[((m.end_index + 16) & 7)];
			}

		}
	}
	
	if (m.piece_type == white_king) {
		board_representation.white_king_square = m.end_index;
		std::string set_castle = board_representation.get_castling_rights();
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
		board_representation.set_castling_rights(set_castle);
		if (m.castle == ' ') {
			board_representation.position_key ^= ZobristHashing::castle_keys[0];
			board_representation.position_key ^= ZobristHashing::castle_keys[2];
		}
	}

	if (m.piece_type == black_king) {
		board_representation.black_king_square = m.end_index;
		std::string set_castle = board_representation.get_castling_rights();
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
		board_representation.set_castling_rights(set_castle);
		if (m.castle == ' ') {
			board_representation.position_key ^= ZobristHashing::castle_keys[1];
			board_representation.position_key ^= ZobristHashing::castle_keys[3];
		}
	}

	if (m.piece_type == white_rook) {
		if (m.start_index == 0) {
			std::string set_castle = board_representation.get_castling_rights();
			set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
			board_representation.set_castling_rights(set_castle);
		}
		if (m.start_index == 7) {
			std::string set_castle = board_representation.get_castling_rights();
			set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
			board_representation.set_castling_rights(set_castle);
		}
	}

	if (m.piece_type == black_rook) {
		if (m.start_index == 112) {
			std::string set_castle = board_representation.get_castling_rights();
			set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
			board_representation.set_castling_rights(set_castle);
		}
		if (m.start_index == 119) {
			std::string set_castle = board_representation.get_castling_rights();
			set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
			board_representation.set_castling_rights(set_castle);
		}
	}
	
	if (m.castle != ' ') {
		make_castle(board_representation, m.castle);
	}
	if (m.capture > 0 && !m.enpassant) {
		board_representation.material_total -= m.capture & piece_neutral_check;
		board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.capture]][m.end_index];
		board_representation.set_halfmove(0);
		--board_representation.piece_total;
		
	}

	if (m.piece_type == white_pawn || m.piece_type == black_pawn) {
		board_representation.set_halfmove(0);
	}
	
	board_representation.remove_piece(m.start_index);
	board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.piece_type]][m.start_index];
	board_representation.add_piece(m.piece_type, m.end_index);
	board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.piece_type]][m.end_index];

	if (m.promotion > 0) {
		board_representation.add_piece(m.promotion, m.end_index);
		board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.promotion]][m.end_index];
		board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.piece_type]][m.end_index];
	}


	made_moves.push_back(m);

	main_info.push_back({board_representation.get_enpassant(), board_representation.get_castling_rights(), board_representation.get_halfmove(), board_representation.position_key});

	board_representation.position_key ^= ZobristHashing::side_key;

	board_representation.set_side(!board_representation.get_side());

	
}

void MoveGen::un_make_move(BoardRepresentation& board_representation, Move m)
{

	made_moves.pop_back();

	main_info.pop_back();

	//std::cout << "main_info size: " << main_info.size() << std::endl;

	if (m.piece_type == white_king) board_representation.white_king_square = m.start_index;

	if (m.piece_type == black_king) board_representation.black_king_square = m.start_index;

	if (m.castle != ' ') unmake_castle(board_representation, m);

	if (m.enpassant == true) board_representation.set_enpassant(13);


	board_representation.remove_piece(m.end_index);
	//board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.piece_type]][m.end_index];

	if (m.capture > 0) {

		board_representation.material_total += m.capture & piece_neutral_check;
		++board_representation.piece_total;

		if (m.enpassant) {
			if (m.piece_type == white_pawn) {
				board_representation.add_piece(m.capture, m.end_index - 16);
				//board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.capture]][m.end_index - 16];
			}
			if (m.piece_type == black_pawn) {
				board_representation.add_piece(m.capture, m.end_index + 16);
				//board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.capture]][m.end_index + 16];
			}
		}
		else {
			board_representation.add_piece(m.capture, m.end_index);
			//board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.capture]][m.end_index];
		}
			
	}

	board_representation.add_piece(m.piece_type, m.start_index);
	board_representation.position_key ^= ZobristHashing::piece_keys[board_representation.index_convert[m.piece_type]][m.start_index];

	/*
	if (made_moves.size() > 0) {
		if (made_moves.back().enpassant && (made_moves.back().piece_type == white_pawn)) {
			board_representation.set_enpassant(m.end_index - 16);
			//board_representation.position_key ^= ZobristHashing::enpassant_keys[((m.end_index - 16) & 7)];
		}
		if (made_moves.back().enpassant && (made_moves.back().piece_type == black_pawn)) {
			board_representation.set_enpassant(m.end_index + 16);
			//board_representation.position_key ^= ZobristHashing::enpassant_keys[((m.end_index + 16) & 7)];
		}
	}
	*/

	board_representation.set_side(!board_representation.get_side());
	//board_representation.position_key ^= ZobristHashing::side_key;

	
	board_representation.set_castling_rights(main_info.back().last_castle);
	board_representation.position_key = main_info.back().last_key;
	board_representation.set_halfmove(main_info.back().halfmove_clock);
	board_representation.set_enpassant(main_info.back().last_enpassant);

}

void MoveGen::make_castle(BoardRepresentation& board_representation, char ch)
{
	std::string set_castle = board_representation.get_castling_rights();

	switch (ch) {

	case ('K'): {
		board_representation.add_piece(white_rook, f1);
		board_representation.remove_piece(h1);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
		//board_representation.position_key ^= ZobristHashing::piece_keys[5][e1];
		//board_representation.position_key ^= ZobristHashing::piece_keys[5][g1];
		board_representation.position_key ^= ZobristHashing::piece_keys[3][h1];
		board_representation.position_key ^= ZobristHashing::piece_keys[3][f1];
		board_representation.position_key ^= ZobristHashing::castle_keys[0];
		break;
	}
	case ('k'): {
		board_representation.add_piece(black_rook, f8);
		board_representation.remove_piece(h8);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
		//board_representation.position_key ^= ZobristHashing::piece_keys[11][e8];
		//board_representation.position_key ^= ZobristHashing::piece_keys[11][g8];
		board_representation.position_key ^= ZobristHashing::piece_keys[9][h8];
		board_representation.position_key ^= ZobristHashing::piece_keys[9][f8];
		board_representation.position_key ^= ZobristHashing::castle_keys[1];
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, d1);
		board_representation.remove_piece(a1);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
		//board_representation.position_key ^= ZobristHashing::piece_keys[5][e1];
		//board_representation.position_key ^= ZobristHashing::piece_keys[5][c1];
		board_representation.position_key ^= ZobristHashing::piece_keys[3][a1];
		board_representation.position_key ^= ZobristHashing::piece_keys[3][d1];
		board_representation.position_key ^= ZobristHashing::castle_keys[2];
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, d8);
		board_representation.remove_piece(a8);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
		//board_representation.position_key ^= ZobristHashing::piece_keys[11][e8];
		//board_representation.position_key ^= ZobristHashing::piece_keys[11][c8];
		board_representation.position_key ^= ZobristHashing::piece_keys[9][a8];
		board_representation.position_key ^= ZobristHashing::piece_keys[9][d8];
		board_representation.position_key ^= ZobristHashing::castle_keys[3];
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);

}

void MoveGen::unmake_castle(BoardRepresentation& board_representation, Move m)
{

	std::string set_castle = board_representation.get_castling_rights();

	switch (m.castle) {

	case('K'): {
		board_representation.add_piece(white_rook, h1);
		board_representation.remove_piece(f1);
		set_castle.push_back('K');
		if (main_info.back().last_castle.find('Q') != std::string::npos) set_castle.push_back('Q');
		break;
	}
	case ('k'): {
		board_representation.add_piece(black_rook, h8);
		board_representation.remove_piece(f8);
		set_castle.push_back('k');
		if (main_info.back().last_castle.find('q') != std::string::npos) set_castle.push_back('q');
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, a1);
		board_representation.remove_piece(d1);
		set_castle.push_back('Q');
		if (main_info.back().last_castle.find('K') != std::string::npos) set_castle.push_back('K');
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, a8);	
		board_representation.remove_piece(d8);
		set_castle.push_back('q');
		if (main_info.back().last_castle.find('k') != std::string::npos) set_castle.push_back('k');
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);
}

//crazy

bool MoveGen::is_attacked(const BoardRepresentation& board_representation, int index, int color)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	
	int target_square = index;

	//PAWN 

	if (color == white) {
		if (board_representation.is_on_board(index - pawn_offset[1]) && board_arr[index - pawn_offset[1]] == white_pawn) return true;
		if (board_representation.is_on_board(index - pawn_offset[2]) && board_arr[index - pawn_offset[2]] == white_pawn) return true;
	}
	else {
		if (board_representation.is_on_board(index + pawn_offset[1]) && board_arr[index + pawn_offset[1]] == black_pawn) return true;
		if (board_representation.is_on_board(index + pawn_offset[2]) && board_arr[index + pawn_offset[2]] == black_pawn) return true;
	}

	//SLIDING -- BISHOP + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		target_square += bishop_offset[i];

		while (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] != null_piece) {

				if (board_arr[target_square] == neutral_bishop + color || board_arr[target_square] == neutral_queen + color) return true;

				else break;
			}

			target_square += bishop_offset[i];

		}
	}

	//LEAPING -- KNIGHT

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + knight_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == neutral_knight + color) return true; 

		}

	}

	//SLIDING -- ROOK + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		target_square += rook_offset[i];

		while (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] != null_piece) {

				if (board_arr[target_square] == neutral_rook + color || board_arr[target_square] == neutral_queen + color) return true;

				else break;
			}

			target_square += rook_offset[i];

		}
	}

	//LEAPING -- KING

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + king_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == neutral_king + color) return true;

		}

	}

	return false;

}

long MoveGen::perft(BoardRepresentation& board_representation, int depth)
{
		long long nodes = 0;


	generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) {
		generate_legal_moves(board_representation, white);
		//std::cout << "white" << std::endl;
	}
	else {
		generate_legal_moves(board_representation, black);
		//std::cout << "black" << std::endl;
	}
	std::vector<Move> help = legal_move_list;

	//print_move_list();


	// bulk count

	if (depth == 1) {
	//	print_move_list();
	//	std::cout << help.size() << std::endl;
	
		return help.size();
	}

	for (const auto& move : help) {
		if (depth == 1) {
			//std::cout << for_print_movegen[move.start_index];
			//std::cout << for_print_movegen[move.end_index];
		}
		//std::cout << "move start: " << move.start_index << "move end: " << move.end_index << std::endl;
		//if (move.capture > 0) std::cout << "WE GOT ONE" << std::endl;
		make_move(board_representation, move);
		nodes += perft(board_representation, depth - 1);
		un_make_move(board_representation, move);
		//std::cout << "move unmade" << std::endl;
	}

	//std::cout << "capture: " << capture_count << std::endl;
	//std::cout << "depth: " << depth << std::endl;
	return nodes;

}

inline bool MoveGen::can_capture(const BoardRepresentation& board_representation, int index, int target_square)
{
	return true;
}

void MoveGen::initialize_struct(const BoardRepresentation& board_representation)
{
	irr_info start = { board_representation.get_enpassant(), board_representation.get_castling_rights(), board_representation.get_halfmove(), board_representation.position_key };
	main_info.push_back(start);
}

void MoveGen::print_move_list()
{
	for (Move& move: legal_move_list) {
	
		std::cout << for_print_movegen[move.start_index];
		std::cout << for_print_movegen[move.end_index];
		std::cout << std::endl;
	}
}

long MoveGen::perft_divide(BoardRepresentation& board_representation, int depth, int divide)
{

	int nodes = 0;

	generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) {
		generate_legal_moves(board_representation, white);
	}
	else {
		generate_legal_moves(board_representation, black);
	}	
	std::vector<Move> help = legal_move_list;

	//print_move_list();


	// bulk count
	if (depth == 1) {
		if (divide == 1) print_move_list();
		nodes = 0;
		return help.size();
	}

	for (const auto& move : help) {

		make_move(board_representation, move);
		nodes += perft_divide(board_representation, depth - 1, divide);
		if (depth == divide) {
			std::cout << for_print_movegen[move.start_index];
			std::cout << for_print_movegen[move.end_index];
			std::cout << " " << nodes << std::endl;
			nodes = 0;
		}
		un_make_move(board_representation, move);

	}

	return nodes;

}

Move MoveGen::string_to_move(BoardRepresentation& board_representation, std::string move)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	std::string from = move.substr(0, 2);
	std::string to = move.substr(2, 4);

	int from_int = for_movegen[from];
	int to_int = for_movegen[to];

	std::string start = std::to_string(from_int);
	std::string end = std::to_string(to_int);

	std::string whole = start + end;

	int move_int = stoi(whole);

	generate_pseudo_legal_moves(board_representation);

	for (const auto& move : move_list) {

		if (move.move_toInt() == move_int) return move;

	}
}

void MoveGen::move_to_string(Move move)
{
	std::cout << for_print_movegen[move.start_index];
	std::cout << for_print_movegen[move.end_index];
	std::cout << std::endl;
}

void MoveGen::reset()
{
	made_moves.clear();
	main_info.clear();
}

void MoveGen::make_nullmove(BoardRepresentation& board_representation)
{
	board_representation.set_side(!board_representation.get_side());
	board_representation.position_key ^= ZobristHashing::side_key;
	made_moves.push_back(Move(13, 13, null_piece, 0, false, ' ', 0, 0));
	main_info.push_back({ board_representation.get_enpassant(), board_representation.get_castling_rights(), board_representation.get_halfmove(), board_representation.position_key });

}

void MoveGen::unmake_nullmove(BoardRepresentation& board_representation) 
{

	board_representation.set_side(!board_representation.get_side());

	made_moves.pop_back();

	main_info.pop_back();

	board_representation.position_key = main_info.back().last_key;

}














