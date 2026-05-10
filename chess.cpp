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

    int dir = (color == 'W') ? -1 : 1;
    int startRow = (color == 'W') ? 6 : 1;

    if (toCol == col && board[toRow][toCol] == nullptr) {

        if (toRow == row + dir)
            return true;

        if (row == startRow &&
            toRow == row + 2 * dir &&
            board[row + dir][col] == nullptr)
            return true;
    }

    if (abs(toCol - col) == 1 &&
        toRow == row + dir) {

        if (board[toRow][toCol] != nullptr &&
            board[toRow][toCol]->getColor() != color)
            return true;
    }

    return false;
}
Knight::Knight(char c, int r, int cl) : Piece(c, r, cl) {}
char Knight::getSymbol() const { return (color == 'W') ? 'N' : 'n'; }
bool Knight::isValidMove(int toRow, int toCol, Piece* board[8][8]) const {
    int dr = abs(toRow - row), dc = abs(toCol - col);
    if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) return false;
    if (board[toRow][toCol] != nullptr && board[toRow][toCol]->getColor() == color) return false;
    return true;
}

Bishop::Bishop(char c, int r, int cl) : Piece(c, r, cl) {}
char Bishop::getSymbol() const { return (color == 'W') ? 'B' : 'b'; }
bool Bishop::isValidMove(int toRow, int toCol, Piece* board[8][8]) const {
    if (abs(toRow - row) != abs(toCol - col)) return false;
    int rStep = (toRow > row) ? 1 : -1;
    int cStep = (toCol > col) ? 1 : -1;
    int r = row + rStep, c = col + cStep;
    while (r != toRow && c != toCol) {
        if (board[r][c] != nullptr) return false;
        r += rStep; c += cStep;
    }
    if (board[toRow][toCol] != nullptr && board[toRow][toCol]->getColor() == color) return false;
    return true;
}
Rook::Rook(char c, int r, int cl)
    : Piece(c, r, cl) {
}

char Rook::getSymbol() const {
    return (color == 'W') ? 'R' : 'r';
}

bool Rook::isValidMove(int toRow,
    int toCol,
    Piece* board[8][8]) const {

    if (toRow != row && toCol != col)
        return false;

    return true;
}
Queen::Queen(char c, int r, int cl) : Piece(c, r, cl) {}
char Queen::getSymbol() const { return (color == 'W') ? 'Q' : 'q'; }
bool Queen::isValidMove(int toRow, int toCol, Piece* board[8][8]) const {
    Rook tempRook(color, row, col);
    Bishop tempBishop(color, row, col);
    return tempRook.isValidMove(toRow, toCol, board) || tempBishop.isValidMove(toRow, toCol, board);
}

King::King(char c, int r, int cl) : Piece(c, r, cl) {}
char King::getSymbol() const { return (color == 'W') ? 'K' : 'k'; }
bool King::isValidMove(int toRow, int toCol, Piece* board[8][8]) const {
    if (abs(toRow - row) > 1 || abs(toCol - col) > 1) return false;
    if (board[toRow][toCol] != nullptr && board[toRow][toCol]->getColor() == color) return false;
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
    cout << "\n    a  b  c  d  e  f  g  h\n";
    cout << "   ------------------------\n";
    for (int i = 0; i < 8; i++) {
        cout << (8 - i) << " | ";
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr) cout << ".  ";
            else cout << grid[i][j]->getSymbol() << "  ";
        }
        cout << "| " << (8 - i) << "\n";
    }
    cout << "   ------------------------\n";
    cout << "    a  b  c  d  e  f  g  h\n\n";
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