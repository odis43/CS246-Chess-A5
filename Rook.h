#ifndef ROOK
#define ROOK

#include "Piece.h"
#include "Tile.h"

class Rook : public Piece {
    public:
        Rook(string colour);
        ~Rook();
        void genMoves(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void moveLeft(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void moveRight(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void moveUp(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void moveDown(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        void print() override;

        void castlingStatus() override;
        bool getCastlingStatus() override;
};

#endif
