#include<iostream>
using namespace std;

int current_Player;
char currentMarker;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard() {
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << " --- | --- | --- \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << " --- | --- | --- \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << " --- | --- | --- \n";
}

bool placemarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_Player;
    }
  
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_Player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_Player;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_Player;

    return 0;
}

void swapPlayerandMarker() {
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    if (current_Player == 1)
        current_Player = 2;
    else
        current_Player = 1;
}

void game() {
    cout << "Player 1 choose your marker (X or O): ";
    char marker;
    cin >> marker;
    current_Player = 1;
    currentMarker = marker;

    drawBoard();
    int playerwon = 0;

    for (int i = 0; i < 9; i++) {
        cout << "It's Player " << current_Player << "'s turn. Enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot, try again.\n";
            i--;
            continue;
        }

        if (!placemarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        playerwon = winner();

        if (playerwon == 1) {
            cout << "🎉 Player 1 wins!\n";
            return;
        }
        if (playerwon == 2) {
            cout << "🎉 Player 2 wins!\n";
            return;
        }

        swapPlayerandMarker();
    }

    cout << "It's a Tie! 🤝\n";
}

int main() {
	cout<<"Tic Tac Toe Game\n";
    game();
    return 0;
}
