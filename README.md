# VirgaCE

VirgaCE is a UCI-compliant chess engine written in C++14. 


## Features

Board Representation:
  - 0x88 mailbox board

Search: 
  - Principal Variation Search (negamax algorithm)
  - Iterative Deepening
  - Transposition Table
    - Zobrist Hashing
  - Move Ordering
    - Hash move priority
    - Killer move heuristic
    - MVV/LVA capture sorting
  - Pruning
    - Futility Pruning
    - Reverse Futility Pruning
    - Null Move Pruning
    - Limited Razoring 
    - Mate Distance Pruning
  - Late Move Reductions
  - Quiescense search
    - Delta pruning

Evaluation: 
  - Material 
  - Piece square tables
  - Mobility
  - King safety

## For the Future

- Change board representation to bitboards
- SSE and staged move generation
- Create multi-threading framework for parallel search
- Add support for NNUE

## Usage

VirgaCE is best used with an existing chess GUI that supports the UCI framework. Two popular choices include [CuteChess](https://cutechess.com/) and [Arena](http://www.playwitharena.de/). The program *can* be used solely through the command line, although intimate knowledge of the [UCI protocol](http://wbec-ridderkerk.nl/html/UCIProtocol.html) is likely required. 
