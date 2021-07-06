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
  - Prunings
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

## Usage
