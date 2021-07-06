#pragma once

#include "Move.h"

class TTEntry{

public:

	long zobrist;
	Move move;
	int depth;
	double eval;
	int type;

	TTEntry(long inz, Move mov, int ind, double ine, int inty) {
		this->zobrist = inz;
		this->move = mov;
		this->depth = ind;
		this->eval = ine;
		this->type = inty;

	}















};