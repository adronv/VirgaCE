#pragma once

#ifndef BOARDINITILIZATION_H
#define BOARDINITILIZATION_H

#include "BoardRepresentation.h"
#include "ZobristHashing.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

class BoardInitialization {


	public:

		void board_initialization(std::string fen_code, BoardRepresentation& board_representation);

	private:
	
		

};

#endif 