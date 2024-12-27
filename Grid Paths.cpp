//Took a bit of help from USACO guide
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
 
int ans = 0;
bool moveTo(vector<vector<bool>>& grid, int i, int j, bool makeChange) {
	if (i < 0 || i >= 7 || j < 0 || j >= 7) return 0;
	if (grid[i][j] == 1) return 0;
	if (makeChange) grid[i][j] = 1;
	return 1;
}
void solve(string& str, vector<vector<bool>>& grid, int ind = 0, int i = 0, int j = 0) {
	if (ind == str.length()) {
		if (i == 6 && j == 0) ans++;
		return;
	}

	//Copied these three optimization from USACO guide
	if (i == 6 && j == 0) return; // if you reach the destination before visitiing all the grids, then terminate
	// if you end up at a place where a pair of opposite cell are non-visited and the other pair of opposite cells are visited, then terminate
	if (moveTo(grid, i, j-1, 0) && moveTo(grid, i, j+1, 0) && !moveTo(grid, i-1, j, 0) && !moveTo(grid, i+1, j, 0)) return; 
	if (moveTo(grid, i-1, j, 0) && moveTo(grid, i+1, j, 0) && !moveTo(grid, i, j-1, 0) && !moveTo(grid, i, j+1, 0)) return;

	if (str[ind] == 'L' || str[ind] == '?') {
		if (moveTo(grid, i, j-1, 1)) { // move to left
			solve(str, grid, ind+1, i, j-1);
			grid[i][j-1] = 0;
		}
	}
	if (str[ind] == 'R' || str[ind] == '?') {
		if (moveTo(grid, i, j+1, 1)) { // move to right
			solve(str, grid, ind+1, i, j+1);
			grid[i][j+1] = 0;
		}
	}
	if (str[ind] == 'U' || str[ind] == '?') {
		if (moveTo(grid, i-1, j, 1)) { // move to upwards
			solve(str, grid, ind+1, i-1, j);
			grid[i-1][j] = 0;
		}
	}
	if (str[ind] == 'D' || str[ind] == '?') {
		if (moveTo(grid, i+1, j, 1)) { //move to below
			solve(str, grid, ind+1, i+1, j);
			grid[i+1][j] = 0;
		}
	}
}
 
int main() {
	string str; cin>>str;
	vector<vector<bool>> grid(7, vector<bool>(7));
	grid[0][0] = 1;
	solve(str, grid);
	cout << ans << nl;
	return 0;
}
