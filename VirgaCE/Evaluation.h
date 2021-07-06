#pragma once
#include "BoardRepresentation.h"

class Evaluation {

	private:

		static const int pawn_pst[7][8];
		static const int knight_pst[8][8];
		static const int bishop_pst[8][8];
		static const int rook_pst[8][8];
		static const int queen_pst[8][8];
		static const int king_pst[8][8];

		static const int knight_mobility[9];
		static const int bishop_mobility[14];
		static const int rook_mobility[15];
		static const int queen_mobility[28];

			
	public:

		Evaluation();
		static double evaluation(const BoardRepresentation& board_representation);
		static double material_eval(const BoardRepresentation& board_representation);
		static int sliding_mobility(const BoardRepresentation& board_representation, int index, const int piece_offset[], int size);
		static int leaping_mobility(const BoardRepresentation& board_representation, int index, const int piece_offset[], int size);
			











};