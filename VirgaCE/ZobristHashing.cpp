#include "ZobristHashing.h"

uint64_t ZobristHashing::piece_keys[12][64];
uint64_t ZobristHashing::enpassant_keys[64];
uint64_t ZobristHashing::castle_keys[4];
uint64_t ZobristHashing::side_key;
std::vector<uint64_t> ZobristHashing::initial_hashvalues;

void ZobristHashing::zobrist_initialization()
{

	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);

	//srand((unsigned)time(0));

	for (int piece = 0; piece < 12; ++piece) {

		for (int square = 0; square < 64; ++square) {

	//		piece_keys[piece][square] = rand() % 1000000;
			//std::cout << dist(gen) << std::endl;
			piece_keys[piece][square] = dist(gen);

		}
	}

	for (int square = 0; square < 64; ++square) enpassant_keys[square] = dist(gen);

	side_key = dist(gen);


}

long ZobristHashing::hash_position(const BoardRepresentation& board_representation)
{

	long zobrist_key = 0;

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	for (int i = 0; i < 120; ++i) {

		if (i % 8 == 0 && i != 0 && i < 112) i = i + 8;

		if (board_arr[i] > 0) {

			switch (board_arr[i]) {

			case (white_pawn):
			{
				zobrist_key ^= piece_keys[0][i];
				break;
			}

			case (white_knight):
			{
				zobrist_key ^= piece_keys[1][i];
				break;
			}

			case(white_bishop):
			{
				zobrist_key ^= piece_keys[2][i];
				break;
			}

			case(white_rook):
			{
				zobrist_key ^= piece_keys[3][i];
				break;
			}

			case(white_queen):
			{
				zobrist_key ^= piece_keys[4][i];
				break;
			}

			case(white_king):
			{
				zobrist_key ^= piece_keys[5][i];
				break;
			}

			case (black_pawn):
			{
				zobrist_key ^= piece_keys[6][i];
				break;
			}

			case (black_knight):
			{
				zobrist_key ^= piece_keys[7][i];
				break;
			}

			case(black_bishop):
			{
				zobrist_key ^= piece_keys[8][i];
				break;
			}

			case(black_rook):
			{
				zobrist_key ^= piece_keys[9][i];
				break;
			}

			case(black_queen):
			{
				zobrist_key ^= piece_keys[10][i];
				break;
			}

			case(black_king):
			{
				zobrist_key ^= piece_keys[11][i];
				break;
			}


			}

		}

	}

	std::string castling_rights = board_representation.get_castling_rights();

	if (castling_rights.find('K') < castling_rights.length()) zobrist_key ^= castle_keys[0];
	if (castling_rights.find('k') < castling_rights.length()) zobrist_key ^= castle_keys[1];
	if (castling_rights.find('Q') < castling_rights.length()) zobrist_key ^= castle_keys[2];
	if (castling_rights.find('q') < castling_rights.length()) zobrist_key ^= castle_keys[3];

	if (board_representation.get_enpassant() != 13) {

		zobrist_key ^= enpassant_keys[board_representation.get_enpassant() & 7];

	}
	if (!board_representation.get_side()) zobrist_key ^= side_key;

	return zobrist_key;


}
