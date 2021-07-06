// VirgaCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include "BoardRepresentation.h"
#include "MoveGen.h"
#include "Search.h"
#include "UCI.h"
#include "TranspositionTable.h"
#include "ZobristHashing.h"
#include "Evaluation.h"

int main()
{

    std::clock_t start = 0;

    UCI uci = UCI();

    uci.UCI_communication();

    // -------------------- FACTORY -------------------------------//


    /*
    
   BoardRepresentation br = BoardRepresentation();

   MoveGen mg = MoveGen();

   Search sh = Search(mg);



   // -------------------------------------------------------------//   

  //  std::cout << "lol";

    
 
    ZobristHashing::zobrist_initialization();

    br.board_initialization("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    mg.initialize_struct(br);
        
    start = std::clock();

    sh.search(br);

    */
 


    /*
        mg.make_move(br, move);

        std::cout << br.position_key << std::endl;
        std::cout << ZobristHashing::hash_position(br) << std::endl;
        std::cout << std::endl;

        mg.un_make_move(br, move);

        std::cout << br.position_key << std::endl;
        std::cout << ZobristHashing::hash_position(br) << std::endl;
        std::cout << std::endl;

        mg.make_nullmove(br);

        std::cout << br.position_key << std::endl;
        std::cout << ZobristHashing::hash_position(br) << std::endl;
        std::cout << std::endl;

        mg.unmake_nullmove(br);

        std::cout << br.position_key << std::endl;
        std::cout << ZobristHashing::hash_position(br) << std::endl;
        std::cout << std::endl;

   */

    

  // -------------------- PERFT -------------------------------//




    //long long x = mg.perft(br, 5);

   //int x = mg.perft_divide(br, 4,4); 

    // std::cout << "nodes: " << x << std::endl;




  // ----------------------------------------------------------//





    auto duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

     

     
    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
