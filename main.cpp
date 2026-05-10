#include "chess.h"
int colCharToIndex(char c) {
    return c - 'a';
}

int rowCharToIndex(char c) {
    return 8 - (c - '0');
}
int main() {

    Board board;
    string input;
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

    cin.ignore();
    cin.get();
    while (!board.isGameOver()) {
        board.display();

        if (board.getCurrentTurn() == 'W')
            cout << "White's Turn: ";
        else
            cout << "Black's Turn: ";

        string from, to;
        cin >> from;

        if (from == "quit") {
            cout << "Game exited.\n";
            return 0;
        }

        cin >> to;

        if (from.length() != 2 || to.length() != 2) {
            cout << "Invalid input format.\n";
            continue;
        }

        int fromCol = colCharToIndex(from[0]);
        int fromRow = rowCharToIndex(from[1]);
        int toCol = colCharToIndex(to[0]);
        int toRow = rowCharToIndex(to[1]);

        if (!board.movePiece(fromRow, fromCol, toRow, toCol)) {
            cout << "Invalid move. Try again.\n";
        }
    }

    board.display();
    cout << "=============================\n";
    char winner = board.getWinner();
    if (winner == 'W')
        cout << "  White Wins!\n";
    else
        cout << "  Black Wins!\n";
    cout << "=============================\n";

    return 0;
}