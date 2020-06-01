#include <iostream>
#include <vector>

using namespace std;

vector<char> matrix = {'o','1','2','3','4','5','6','7','8','9'};

int player = 1;
// bool draw = false;

void board(vector<char> matrix) {
	cout << "     |     |     " << endl;
    cout << "  " << matrix[1] << "  |  " << matrix[2] << "  |  " << matrix[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << matrix[4] << "  |  " << matrix[5] << "  |  " << matrix[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << matrix[7] << "  |  " << matrix[8] << "  |  " << matrix[9] << endl;

    cout << "     |     |     " << endl << endl;
}

bool checkWin(vector<char> matrix) {
	if (matrix[1] == '0' && matrix[5] == '0' && matrix[9] == '0') return true;
	else if (matrix[3] == '0' && matrix[5] == '0' && matrix[7] == '0') return true;
	else if (matrix[1] == '0' && matrix[4] == '0' && matrix[7] == '0') return true;
	else if (matrix[1] == '0' && matrix[2] == '0' && matrix[3] == '0') return true;
	else if (matrix[3] == '0' && matrix[6] == '0' && matrix[9] == '0') return true;
	else if (matrix[7] == '0' && matrix[8] == '0' && matrix[9] == '0') return true;
	else if (matrix[2] == '0' && matrix[5] == '0' && matrix[8] == '0') return true;
	else if (matrix[4] == '0' && matrix[5] == '0' && matrix[6] == '0') return true;


	if (matrix[1] == 'X' && matrix[5] == 'X' && matrix[9] == 'X') return true;
	else if (matrix[3] == 'X' && matrix[5] == 'X' && matrix[7] == 'X') return true;
	else if (matrix[1] == 'X' && matrix[4] == 'X' && matrix[7] == 'X') return true;
	else if (matrix[1] == 'X' && matrix[2] == 'X' && matrix[3] == 'X') return true;
	else if (matrix[3] == 'X' && matrix[6] == 'X' && matrix[9] == 'X') return true;
	else if (matrix[7] == 'X' && matrix[8] == 'X' && matrix[9] == 'X') return true;
	else if (matrix[2] == 'X' && matrix[5] == 'X' && matrix[8] == 'X') return true;
	else if (matrix[4] == 'X' && matrix[5] == 'X' && matrix[6] == 'X') return true;
}

bool checkDraw(vector<char> matrix) {
	if (matrix[1] == '0' || matrix[1] == 'X')
		if (matrix[2] == '0' || matrix[2] == 'X')
			if (matrix[3] == '0' || matrix[3] == 'X')
				if (matrix[4] == '0' || matrix[4] == 'X')
					if (matrix[5] == '0' || matrix[5] == 'X')
						if (matrix[6] == '0' || matrix[6] == 'X')
							if (matrix[7] == '0' || matrix[7] == 'X')
								if (matrix[8] == '0' || matrix[8] == 'X')
									if (matrix[9] == '0' || matrix[9] == 'X')
										return true;
}

int main() {
	cout << "Start Game: \n" << endl;
	cout << "Press '0' to quit\n\n";
	// board(matrix);
	// cout << "\nPlayer " << player << ": \n";
	// int turn = 9;
	while(true) {
		board(matrix);

		cout << "\nPlayer " << player << ": \n";
		int move; cin >> move;

		if (move == 0) {
			cout << "Game Finished\n";
			break;
		}

		if (matrix[move] == '0' || matrix[move] == 'X' || move > 9 || move < 1) {
			board(matrix);
			cout << "Invalid move! Try again!: \n";
			continue;
		}

		// turn--;
		if (player == 1) {
			matrix[move] = '0';
			player = 2;
		}

		else if (player == 2) {
			matrix[move] = 'X';
			player = 1;
		}

		if (checkDraw(matrix)) {
			board(matrix);
			
			cout << "OOPS!! DRAW!!\n\n";
			break;
		}

		if (checkWin(matrix)) {
			board(matrix);

			player = (player == 1 ? 2 : 1);

			cout << "Game Finished\n";
			cout << "Player " << player << " wins!!\n\n";
			break;
		}
	}

	return 0;
}
