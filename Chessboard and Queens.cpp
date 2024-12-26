#include <bits/stdc++.h>
using namespace std;

int ans = 0;

vector<string> makeAMove(vector<string> chessBoard, int i, int j) {
	for (int k=0; k<8; k++) {
		chessBoard[i][k] = '*';
		chessBoard[k][j] = '*';
	}
	for (int i_=i-min(i, j), j_=j-min(i, j); i_<8 && j_<8; i_++, j_++) chessBoard[i_][j_] = '*';
	for (int i_=0, j_=i+j; i_<8; i_++, j_--) if (j_<8 && j_>=0) chessBoard[i_][j_] = '*';
	return chessBoard;
}
void solve(vector<string> chessBoard, int ind = 0, int placed = 0) {
	if (ind == 8) {
		if (placed == 8) ans++;
		return;
	}
	for (int i=0; i<8; i++) {
		if (chessBoard[ind][i] == '.')
			solve(
				makeAMove(chessBoard, ind, i),
				ind+1,
				placed+1
			);
	}
}

int main() {
	vector<string> chessBoard(8);
	for (int i=0; i<8; i++) cin>>chessBoard[i];
	solve(chessBoard);
	cout << ans;
	return 0;
}

