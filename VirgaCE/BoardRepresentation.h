#pragma once

#ifndef boardrepresentation_h
#define boardrepresentation_h

#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <array>

#include "Common.h"
#include "Piece.h"


class BoardRepresentation {

	private: 

		std::array <int, board_size> chess_board;
		std::map<int, char> for_print;
		bool side_turn;
		std::string castling_rights; 
		unsigned int enpassant = NULL_ENPASSANT;
		unsigned int half_move;

		// EXPERIMENTAL BULLSHIT

		typedef union neighbor_table {
			unsigned char direction[8];
			uint64_t all;
		};

		neighbor_table neighbors[10 * 10];


	public:

		BoardRepresentation();

		friend std::ostream& operator<<(std::ostream& o, std::vector <std::string> vec );
		void print_the_board();
		void add_piece(unsigned char piece, unsigned char index);
		void add_pieceo(unsigned char index);
		void remove_piece(unsigned char index);
		bool is_on_board(int index) const;
		int return_square(std::string square);
		bool dead_position();
		void board_initialization(std::string fen_code);

		int white_king_square;
		int black_king_square;
		long position_key;
		int piece_total;
		int material_total;
		int piece_count; 
		std::array <int, 135> index_convert = { 0 };
		std::array <double, 67> value_convert = { 0 };

		// getters

		std::array<int, board_size> get_chess_board() const { return chess_board; }
		int get_enpassant() const { return enpassant; }
		bool get_side() const { return side_turn; }
		std::string get_castling_rights() const { return castling_rights; }
		int get_halfmove() const { return half_move; }

		// setters
		void set_chess_board(std::array<int, board_size> b);
		void set_side(bool side);
		void set_castling_rights(std::string str);
		void set_enpassant(int index);
		void set_halfmove(int n);


};

#endif 