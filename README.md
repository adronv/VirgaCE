# VirgaCE

VirgaCE is a UCI-compliant chess engine written in C++14. 


## Features

Board Representation:
  - 0x88 mailbox board

Search: 
  - Principal Variation Search (negamax algorithm)
  - Iterative Deepening
  - Transposition Table
  - Move Ordering
    - Hash move priority
    - Killer move heuristic
    - MVV/LVA capture sorting
