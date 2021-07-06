#pragma once

#include <cstddef>
#include <map>


enum piece {
    null_piece = 0x00,
    neutral_pawn = 0x04,
    neutral_queen = 0x40,
    neutral_rook = 0x20,
    neutral_knight = 0x08,
    neutral_king = 0x80,
    neutral_bishop = 0x010,
    white = 0x01,
    black = 0x02,
    piece_color_check = 0x03,
    white_pawn = 0x05,
    white_knight = 0x09,
    white_bishop = 0x011,
    white_rook = 0x21,
    white_queen = 0x41,
    white_king = 0x81,
    black_pawn = 0x06,
    black_knight = 0xA,
    black_bishop = 0x012,
    black_rook = 0x22,
    black_queen = 0x42,
    black_king = 0x82,
    piece_neutral_check = 0xFC,
};

enum piece_flags {









};

static const int piece_ordering[12] = { white_pawn, white_knight, white_bishop, white_rook, white_queen, white_king, black_pawn, black_knight, black_bishop, black_rook, black_queen, black_king };


