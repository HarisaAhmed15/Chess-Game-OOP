#pragma once
#include <iostream>
#include <string>
using namespace std;

class Piece {
protected:
    char color;
    int row, col;
public:
    Piece(char c, int r, int cl);
    virtual ~Piece() {}
    char getColor() const;
    int getRow() const;
    int getCol() const;
    void setPosition(int r, int c);
    virtual bool isValidMove(int toRow, int toCol, Piece* board[8][8]) const = 0;
    virtual char getSymbol() const = 0;
};

class Pawn : public Piece {
public:
    Pawn(char c, int r, int cl);
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) const override;
    char getSymbol() const override;
};
class Knight : public Piece {
public:
    Knight(char c, int r, int cl);
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) const override;
    char getSymbol() const override;
};

class Bishop : public Piece {
public:
    Bishop(char c, int r, int cl);
    bool isValidMove(int toRow, int toCol, Piece* board[8][8]) const override;
    char getSymbol() const override;
};
class Rook : public Piece {
public:
    Rook(char c, int r, int cl);

    bool isValidMove(int toRow,
        int toCol,
        Piece* board[8][8]) const override;

    char getSymbol() const override;
};

class Board {
private:
    Piece* grid[8][8];
    char currentTurn;
    bool whiteKingAlive;
    bool blackKingAlive;
public:
    Board();
    ~Board();
    void initialize();
    void display() const;
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
    bool isGameOver() const;
    char getWinner() const;
    char getCurrentTurn() const;
    void switchTurn();
    bool isInBounds(int r, int c) const;
};

