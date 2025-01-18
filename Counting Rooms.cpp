#include <bits/stdc++.h>
using namespace std;

void help(vector<string>& grid, int&n, int& m, int i, int j) {
	grid[i][j] = '#';
	if (i+1 < n && grid[i+1][j] == '.') help(grid, n, m, i+1, j);
	if (i-1>= 0 && grid[i-1][j] == '.') help(grid, n, m, i-1, j);
	if (j+1 < m && grid[i][j+1] == '.') help(grid, n, m, i, j+1);
	if (j-1>= 0 && grid[i][j-1] == '.') help(grid, n, m, i, j-1);
}

int solve(vector<string>& grid, int& n, int& m) {
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] == '.') {
				ans++;
				help(grid, n, m, i, j);
			}
		}
	}
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<string> grid(n);
	for (string& str: grid) cin>>str;
	cout << solve(grid, n, m);
	return 0;
}


