#include "chess.h"

Piece::Piece(char c, int r, int cl)
    : color(c), row(r), col(cl) {
}

char Piece::getColor() const {
    return color;
}

int Piece::getRow() const {
    return row;
}

int Piece::getCol() const {
    return col;
}

void Piece::setPosition(int r, int c) {
    row = r;
    col = c;
}

Pawn::Pawn(char c, int r, int cl)
    : Piece(c, r, cl) {
}

char Pawn::getSymbol() const {
    return (color == 'W') ? 'P' : 'p';
}

bool Pawn::isValidMove(int toRow, int toCol, Piece* board[8][8]) const {
    return true;
}

Board::Board() : currentTurn('W') {

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            grid[i][j] = nullptr;

    initialize();
}

Board::~Board() {

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            delete grid[i][j];
}

void Board::initialize() {

    for (int j = 0; j < 8; j++) {
        grid[1][j] = new Pawn('B', 1, j);
        grid[6][j] = new Pawn('W', 6, j);
    }
}

void Board::display() const {

    cout << "\nChess Board\n";

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            if (grid[i][j] == nullptr)
                cout << ". ";
            else
                cout << grid[i][j]->getSymbol() << " ";
        }

        cout << endl;
    }
}

bool Board::movePiece(int fromRow, int fromCol,
    int toRow, int toCol) {

    return true;
}

char Board::getCurrentTurn() const {
    return currentTurn;
}

void Board::switchTurn() {

    currentTurn = (currentTurn == 'W') ? 'B' : 'W';
}

bool Board::isInBounds(int r, int c) const {

    return r >= 0 && r < 8 &&
        c >= 0 && c < 8;
}