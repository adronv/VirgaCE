#include "UCI.h"
#include <iostream>
#include <sstream>

void UCI::UCI_communication()
{
	std::string uci_line;

	ZobristHashing::zobrist_initialization();

	MoveGen mg = MoveGen();

	Search sg = Search(mg);

	sg.search_init();

	BoardRepresentation br = BoardRepresentation();

	mg.initialize_struct(br);

	while (true) {

		if (getline(std::cin, uci_line)) {

			std::istringstream iss(uci_line);
			std::string commandName = "";
			iss >> commandName;

			if (commandName == "uci") {
				std::cout << "id name VirgaCE" << std::endl;
				std::cout << "id author AdronVrona" << std::endl;
				std::cout << "uciok" << std::endl;
			}
			if (commandName == "quit") {
				std::cout << "Bye Bye" << std::endl;
				break;
			}
			if (commandName == "isready") {
				std::cout << "readyok" << std::endl;
			}
			if (commandName == "ucinewgame") {
				std::cout << "OOOOOT" << std::endl;
			}

			if (commandName == "position") {

				std::string command;
				std::string fen;

				mg.reset();
				sg.reset();

				iss >> command;

				if (command == "startpos") {

					std::cout << "startposss" << std::endl;
					br.board_initialization("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

				}

				else if (command == "fen") {

					while (iss >> fen && fen != "moves")
					{
						fen += fen + " ";
					}

					br.board_initialization(fen);
				}

				iss >> command; 

				if (command == "moves") {

					while (iss >> command) {

						mg.make_move(br, mg.string_to_move(br, command));

					}

				}

			}

			if (commandName == "go") {

				sg.search(br);

				std::cout << "bestmove ";
				mg.move_to_string(sg.engine_move);

			}

		}

	}
}
