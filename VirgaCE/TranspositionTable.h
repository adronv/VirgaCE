#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "TTEntry.h"
#include "MoveGen.h"
#include "ZobristHashing.h"

#ifndef TT_CLASS 
#define TT_CLASS


class TranspositionTable {

private:


    TTEntry* table;
    uint64_t table_size;
    int counter = 0;

public:


    TranspositionTable(uint64_t size) {

        table_size = (1024 * 1024 * size)/sizeof(TTEntry);
        uint64_t mb = 1024 * 1024 * size;
        auto xds = mb / sizeof(TTEntry);
        table = (TTEntry*)std::malloc(mb);
        //std::cout << "size: " << sizeof(TTEntry) << std::endl;
   
    }

    void put(long key, Move move, int depth, double eval, int type) {

        ++counter;

       // std::cout << "key: " << key << std::endl;
        //TTEntry entry = get(key);

            int hash = (key % table_size);

            if (hash < 0) hash = hash * -1;

           // std::cout << "hash: " << hash << std::endl;

            table[hash] = TTEntry{ key, move, depth, eval, type };


        

    }

    TTEntry get(int key) {

        int hash = (key % table_size);

        if (hash < 0) hash = hash * -1;

        return table[hash];

    }

    std::vector<Move> extract_pv(BoardRepresentation board_representation, int depth) {

        MoveGen mg = MoveGen();

        std::vector<Move> current_pv;

        TTEntry current = get(ZobristHashing::hash_position(board_representation));

       
        for (int i = 0; i < depth; ++i) {

           // std::cout << "dasdasdsad" << counter << std::endl;

           // std::cout << "start: " << current.move.start_index << std::endl;
           // std::cout << "end: " << current.move.end_index << std::endl;

            Move current_move = current.move;

            /*
            std::cout << "start: " << current_move.start_index << std::endl;
            std::cout << "end: " << current_move.end_index << std::endl;
            std::cout << "node: " << current.type << std::endl;
            std::cout << "depth: " << current.depth << std::endl;
            std::cout << std::endl;
            */

            current_pv.push_back(current_move);

            if (current.depth > 0) {
                mg.make_move(board_representation, current_move);
            }

            current = get(ZobristHashing::hash_position(board_representation));

        }

        return current_pv;

    }

    void clear_TT() {
        for (int i = 0; i < 1024 * 1024 * 4 + 599258; ++i) {
            table[i] = TTEntry(0, Move(13, 13, null_piece, 0, false, ' ', 0, 0), 0, 0, 0);
        }
    }

  /*  TranspositionTable() {
        table = new TTEntry * [1000];
        for (int i = 0; i < 1000; i++)
            table[i] = NULL;
    }

    TTEntry* get(int key) {
        int hash = (key % 1000);
        while (table[hash] != NULL && table[hash]->zobrist != key)
            hash = (hash + 1) % 1000;
        if (table[hash] == NULL) {
            std::cout << "oops";
        }
        else return table[hash];
    }

    void put(long key, int from, int to, int depth, double eval, int type) {
        int hash = (key % 1000);
        while (table[hash] != NULL && table[hash]->zobrist != key)
            hash = (hash + 1) % 1000;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new TTEntry(key, from, to, depth, eval, type);
    }

    ~TranspositionTable() { 
        for (int i = 0; i < 1000; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }*/
};


#endif










