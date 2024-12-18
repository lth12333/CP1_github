// piece.h
#ifndef PIECE_H
#define PIECE_H

typedef struct {
    char type;  // 'K' (King), 'Q' (Queen), 'R' (Rook), 'B' (Bishop), 'N' (Knight), 'P' (Pawn)
    char color; // 'W' (White), 'B' (Black)
} Piece;

#endif