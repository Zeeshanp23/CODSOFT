#include <iostream>
#include <vector>
#include <string>

using namespace std;

// initialize the game board
vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// define game functions
void display_board() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "--+---+--" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "--+---+--" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

int player_input(string player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9):";
    cin >> move;
    while (move < 1 || move > 9 || board[move-1] != "-") {
        cout << "Invalid move, please try again:";
        cin >> move;
    }
    return move-1;
}

bool check_win(string player) {
    vector<vector<int>> win_patterns = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (vector<int> pattern : win_patterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool check_draw() {
    for (string cell : board) {
        if (cell == "-") {
            return false;
        }
    }
    return true;
}

int main() {
    // main game loop
    string player = "X";
    display_board();
    while (true) {
        int move = player_input(player);
        board[move] = player;
        display_board();
        if (check_win(player)) {
            cout << "Player " << player << " wins!" << endl;
            break;
        } else if (check_draw()) {
            cout << "Game is a draw." << endl;
            break;
        }
        player = (player == "X") ? "O" : "X";
    }

    // ask to play again
    char play_again;
    cout << "Play again? (y/n)";
    cin >> play_again;
    while (play_again == 'y') {
        board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};
        player = "X";
        display_board();
        while (true) {
            int move = player_input(player);
            board[move] = player;
            display_board();
            if (check_win(player)) {
                cout << "Player " << player << " wins!" << endl;
                break;
            } else if (check_draw()) {
                cout << "Game is a draw." << endl;
                break;
            }
            player = (player == "X") ? "O" : "X";
        }
        cout << "Play again? (y/n)";
        cin >> play_again;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
