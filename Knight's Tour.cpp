//Warnsdorf's rule
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {-1, -2}};

int findPossMoves(int i, int j, vector<vector<int>>& grid) {
	int ans = 0;
	for (int k=0; k<8; k++) {
		int newI = i + dir[k][0];
		int newJ = j + dir[k][1];
		if (newI >= 0 && newI < 8 && newJ >= 0 && newJ < 8 && grid[newI][newJ] == 0) ans++;
	}
	return ans;
}

void dfs(vector<vector<int>>& grid, int i, int j, bool& found, int depth = 1) {
	if (found) return;
	grid[i][j] = depth;
	if (depth == 64) {
		found = 1;
		return;
	}
	vector<vector<int>> ordAdj;
	for (int k=0; k<8; k++) {
		int newI = i + dir[k][0];
		int newJ = j + dir[k][1];
		if (newI >= 0 && newI < 8 && newJ >= 0 && newJ < 8 && grid[newI][newJ] == 0)
			ordAdj.push_back({findPossMoves(newI, newJ, grid), newI, newJ});
	}
	sort(ordAdj.begin(), ordAdj.end());
	for (int k=0; k<ordAdj.size() && !found; k++) dfs(grid, ordAdj[k][1], ordAdj[k][2], found, depth+1);
	if (!found) grid[i][j] = 0;
} 

int main() {
	int x, y; cin>>x>>y;
	vector<vector<int>> grid(8, vector<int>(8));
	bool found = 0;
	dfs(grid, y-1, x-1, found);
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++)
			cout << grid[i][j] << ' ';
		cout << endl;
	}
	return 0;
}

