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

## For the Far Future

- Change board representation to bitboards
- SSE and staged move generation
- Create multi-threading framework for parallel search
- Syzygy tablebases 
- Add support for NNUE

## Usage

VirgaCE is best used with an existing chess GUI that supports the UCI framework. Two popular choices include [CuteChess](https://cutechess.com/) and [Arena](http://www.playwitharena.de/). The program *can* be used solely through the command line, although intimate knowledge of the [UCI protocol](http://wbec-ridderkerk.nl/html/UCIProtocol.html) is likely required. 

## Acknowledgements 

I would have been spinning my wheels with this project if it weren't for the assistance of many different communities and individuals, including: 
- [Chess Programming Wiki](https://www.chessprogramming.org/Main_Page)
- [TalkChess](http://talkchess.com/forum3/index.php)
- [/r/chessprogramming](https://www.reddit.com/r/chessprogramming/) (and specifically to u/tsojtsojtsoj for being brilliant)
- [Dalton He](https://github.com/daltonhe/SAVANT) (thanks for the guidance friend :^) )
- [Kieren Pearson](https://github.com/KierenP/Halogen)
- [Mikko Aarnos](https://github.com/mAarnos/Hakkapeliitta)
- [Stockfish](https://github.com/official-stockfish/Stockfish)

