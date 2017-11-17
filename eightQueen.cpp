#include <iostream>

using namespace std;

void placeQueen(int row, int (*board)[8], int* queen);
void removeLastChess(int row, int (*board)[8]);
void queenAttack(int row, int coloum, int (*board)[8], int* queen);
void print(const int* queen);


int main(){
	int queen[8];
	int board[8][8];
	for(int i = 0; i < 8; i++){
		queen[i] = -1;
		for(int j = 0; j < 8; j++){
			board[i][j] = -1;
		}
	}
	placeQueen(0, board, queen);
	return 0;
}

void placeQueen(int row, int (*board)[8], int* queen){
	bool flag = false;
	for(int i = queen[row] + 1; i < 8; i++){
		if(board[row][i] == -1){
			flag = true;
			queenAttack(row, i, board, queen);
			break;
		}
	}
	if(!flag){
		if(row == 0) return;
		removeLastChess(row, board);
		placeQueen(row - 1, board, queen);
	}
	else{
		if(row == 7){
			print(queen);
			removeLastChess(row, board);
			placeQueen(row - 1, board, queen);
		}
		else{
			queen[row + 1] = -1;
			placeQueen(row + 1, board, queen);
		}
	}
}

void removeLastChess(int row, int (*board)[8]){
	for (int j = row; j < 8; j++) {
		for (int k = 0; k < 8; k++) {
			if (board[j][k] == row - 1)
				board[j][k] = -1;
		}
	}
}

void queenAttack(int row, int coloum, int (*board)[8], int* queen){
	queen[row] = coloum;
	for(int i = row + 1; i < 8; i++){
		if(board[i][coloum] == -1) board[i][coloum] = row;
		int m = coloum + i - row;
		int n = coloum - i + row;
		if(m < 8 && board[i][m] == -1) board[i][m] = row;
		if(n >= 0 && board[i][n] == -1) board[i][n] = row;
	}
}

void print(const int* queen){
	cout <<  "a" << queen[0] << " b" << queen[1];
	cout << " c" << queen[2] << " d" << queen[3];
	cout << " e" << queen[4] << " f" << queen[5];
	cout << " g" << queen[6] << " h" << queen[7];
	cout << endl;
}

