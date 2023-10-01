#include <iostream>
#include <string>

using namespace std;

// Initialize game board to empty spaces
char gameBoard[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Print out the current game board
void printBoard() {
    cout << "   1  | 2  | 3 " << endl;
    cout << "  ----------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << "| " << gameBoard[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "  ------------" << endl;
    }
}

// Check if there is a winner
bool checkWinner(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (gameBoard[0][j] == player && gameBoard[1][j] == player && gameBoard[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) {
        return true;
    }
    if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    // Initialize player and game status variables
    string player = "X";
    bool gameOver = false;
    
    // Loop until the game is over
    while (!gameOver) {
        // Print out the current game board
        printBoard();
        
        // Ask the player for their move
        int row, col;
        cout << player << ", enter row and column numbers (1-3): ";
        cin >> row >> col;
        
        // Check if move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        if (gameBoard[row-1][col-1] != ' ') {
            cout << "That cell is already occupied! Try again." << endl;
            continue;
        }
        
        // Update game board with player's move
        gameBoard[row-1][col-1] = player[0];
        
        // Check for winner
        if (checkWinner(player[0])) {
            printBoard();
            cout << player << " wins! Game over." << endl;
            gameOver = true;
        }
        // Check for tie
        else if (gameBoard[0][0] != ' ' && gameBoard[0][1] != ' ' && gameBoard[0][2] != ' ' &&
                 gameBoard[1][0] != ' ' && gameBoard[1][1] != ' ' && gameBoard[1][2] != ' ' &&
                 gameBoard[2][0] != ' ' && gameBoard[2][1] != ' ' && gameBoard[2][2] != ' ') {
            printBoard();
            cout << "It's a tie! Game over." << endl;
            gameOver = true;
        }
        // Switch player
        else {
            player = (player == "X") ? "O" : "X";
        }
    }
    
    return 0;
}