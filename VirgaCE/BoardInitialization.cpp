#include "BoardInitialization.h"
#include "BoardRepresentation.h"


void BoardInitialization::board_initialization(std::string fen_code, BoardRepresentation& board_representation) {

	assert(fen_code.length() > 0);

	std::istringstream iss(fen_code);

	std::string fen_strings;

	iss >> fen_strings;

	int temp_file = 7;
	
	int temp_rank = 1;

	for (int i = 0; i < fen_strings.length(); ++i) {

		char ch = fen_code.at(i);

		if (isdigit(ch)) {

			for (int j = 0; j < (ch - '0'); ++j) {

				int square_index = temp_file * 16 + (temp_rank - 1);

				board_representation.add_pieceo(square_index);
				
				++temp_rank;
			}

		}

		else {

			int square_index = 0;

			switch (ch) {

				// BLACK PIECES

			case 'p':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_pawn, square_index);
				break;


			case 'n':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_knight, square_index);
				break;


			case 'b':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_bishop, square_index);
				break;


			case 'r':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_rook, square_index);
				break;


			case 'q':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_queen, square_index);
				break;


			case 'k':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(black_king, square_index);
				board_representation.black_king_square = square_index;
				break;



				// WHITE PIECES


			case 'P':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_pawn, square_index);
				break;


			case 'N':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_knight, square_index);
				break;


			case 'B':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_bishop, square_index);
				break;


			case 'R':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_rook, square_index);
				break;


			case 'Q':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_queen, square_index);
				break;


			case 'K':
				square_index = temp_file * 16 + (temp_rank - 1);
				board_representation.add_piece(white_king, square_index);
				board_representation.white_king_square = square_index;
				break;

			case '/':
				temp_rank = 0;
				--temp_file;
				break;

			}

			++temp_rank;

		}
	}




	char side_move;

	iss >> side_move;

	if (side_move == 'b') board_representation.set_side(false);
	else board_representation.set_side(true);

	std::string castle_rights;

	iss >> castle_rights; 

	board_representation.set_castling_rights(castle_rights);

	std::string en_passant;

	iss >> en_passant;

	board_representation.set_enpassant(13);

	if (en_passant != "-") {

		board_representation.set_enpassant(board_representation.return_square(en_passant));
			
	}

	int half_move;

	iss >> half_move;

	board_representation.set_halfmove(half_move);

	board_representation.position_key = ZobristHashing::hash_position(board_representation);


}
