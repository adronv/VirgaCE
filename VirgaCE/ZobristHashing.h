#pragma once

#ifndef ZOBRISTHASHING_CLASS
#define ZOBRISTHASHING_CLASS

#include "BoardRepresentation.h"

#include <vector>
#include <random>

class ZobristHashing {


public:

	static uint64_t piece_keys[12][64];
	static uint64_t enpassant_keys[64];
	static uint64_t castle_keys[4];
	static uint64_t side_key;
	static std::vector<uint64_t> initial_hashvalues;

	static void zobrist_initialization();
	static long hash_position(const BoardRepresentation& board_representation);




























};

#endif