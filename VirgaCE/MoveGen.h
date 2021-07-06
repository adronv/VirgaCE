
#ifndef MOVEGEN_CLASS 
#define MOVEGEN_CLASS

#include "Move.h"
#include "BoardRepresentation.h"
#include "ZobristHashing.h"

#include <list>
#include <iostream>
#include <string>


class MoveGen {


	private:

		std::vector<Move> move_list;
		std::vector<Move> legal_move_list;
		std::vector<Move> made_moves;

		struct irr_info {
			int last_enpassant;
			std::string last_castle;
			int halfmove_clock;
			long last_key;
		};

		std::vector <struct irr_info> main_info;

	public: 

		std::map<int, std::string> for_print_movegen;
		std::map<std::string, int> for_movegen;

		//getters
		std::vector<Move> get_move_list() { return move_list; }
		std::vector<Move> &get_legal_move_list() { return legal_move_list; }
		std::vector <struct irr_info> &get_main_info() { return main_info; }

		//generate moves
		void generate_pl_pawn_moves(const BoardRepresentation& board_representation, int index);
		void generate_pl_sliding_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size);
		void generate_pl_leaping_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size);
		void generate_pl_castle_moves(const BoardRepresentation& board_representation, int index);
		void generate_pseudo_legal_moves(const BoardRepresentation& board_representation);
		void generate_legal_moves(BoardRepresentation& board_representation, int color);

		//make-unmake moves
		void make_move(BoardRepresentation& board_representation, Move m);
		void un_make_move(BoardRepresentation& board_representation, Move m);
		void make_castle(BoardRepresentation& board_representation, char ch);
		void unmake_castle(BoardRepresentation& board_representation, Move m);
		void make_nullmove(BoardRepresentation& board_representation);
		void unmake_nullmove(BoardRepresentation& board_representation);


		//helper methods
		void initialize_struct(const BoardRepresentation& board_representation);
		inline bool is_attacked(const BoardRepresentation& board_representation, int index, int color);
		inline bool can_capture(const BoardRepresentation& board_representation, int index, int target_square);
		long perft(BoardRepresentation& board_representation, int depth);
		long perft_divide(BoardRepresentation& board_representation, int depth, int divide);	
		Move string_to_move(BoardRepresentation& board_representation, std::string move);
		void move_to_string(Move move);
		void reset();
		void print_move_list();

		MoveGen();









};

#endif