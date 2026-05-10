#include "chess.h"

int main() {

    Board board;

    cout << "=============================\n";
    cout << "     CONSOLE CHESS GAME      \n";
    cout << "=============================\n";
    cout << "\nHOW TO PLAY\n";
    cout << "-----------------------------\n";
    cout << "Two players take turns: White moves first.\n";
    cout << "White pieces : P R N B Q K  (UPPERCASE)\n";
    cout << "Black pieces : p r n b q k  (lowercase)\n";
    cout << "\nPIECE LEGEND\n";
    cout << "  P/p = Pawn     R/r = Rook\n";
    cout << "  N/n = Knight   B/b = Bishop\n";
    cout << "  Q/q = Queen    K/k = King\n";
    cout << "\nHOW TO ENTER A MOVE\n";
    cout << "  Type the square to move FROM, space, then square to move TO.\n";
    cout << "  Columns are letters a to h (left to right).\n";
    cout << "  Rows are numbers 1 to 8 (bottom to top).\n";
    cout << "  Example: e2 e4  moves the piece on e2 to e4\n";
    cout << "  Example: g1 f3  moves the Knight from g1 to f3\n";
    cout << "\nRULES REMINDER\n";
    cout << "  - You cannot move the opponent's pieces.\n";
    cout << "  - Invalid moves are rejected; just try again.\n";
    cout << "  - The game ends when a King is captured.\n";
    cout << "  - Type 'quit' at any time to exit.\n";
    cout << "-----------------------------\n";
    cout << "\nPress ENTER to start...";

    board.display();

    return 0;
}