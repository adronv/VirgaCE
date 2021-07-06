#pragma once

#include <bit>
#include <cstdint>
#include "Common.h"
#include "MoveGen.h"

class Position {

	const unsigned long long attack_mask = 0x1111111111111111;
	const unsigned long long slider_mask = 0x0FFFFF0000000000;

	int piece_list[list_size];

	int attack_map[list_size * 2];

















};