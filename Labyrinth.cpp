#include <bits/stdc++.h>
using namespace std;

void printPath(string& grid, int currLoc, int& n, int& m, vector<int>& pathLen) {
	if (grid[currLoc] == 'B') return;
	pathLen[currLoc] = 1e9;
	int mini = 1e9;
	if (currLoc-m >= 0) mini = min(mini, pathLen[currLoc-m]);
	if (currLoc+m < n*m) mini = min(mini, pathLen[currLoc+m]);
	if (currLoc%m-1 >= 0) mini = min(mini, pathLen[currLoc-1]);
	if (currLoc%m+1 < m) mini = min(mini, pathLen[currLoc+1]);

	if (currLoc-m >= 0 && pathLen[currLoc-m] == mini) {
		cout << "U";
		printPath(grid, currLoc-m, n, m, pathLen);
	}
	else if (currLoc+m < n*m && pathLen[currLoc+m] == mini) {
		cout << "D";
		printPath(grid, currLoc+m, n, m, pathLen);
	}
	else if (currLoc%m-1 >= 0 && pathLen[currLoc-1] == mini) {
		cout << "L";
		printPath(grid, currLoc-1, n, m, pathLen);
	}
	else {
		cout << "R";
		printPath(grid, currLoc+1, n, m, pathLen);
	}
}

void solve(int& n, int& m, string& grid) {
	int A, B;
	for (A=0; A<n*m; A++) if (grid[A] == 'A') break;
	for (B=0; B<n*m; B++) if (grid[B] == 'B') break;
	vector<int> pathLen(n*m, 1e9);
	pathLen[B] = 0;
	queue<pair<int,int>> q;
	q.push({B, 0});
	bool found = 0;
	while (q.size()) {
		int currLoc = q.front().first, currDist = q.front().second;
		q.pop();
		if (grid[currLoc] == 'A') {
			found = 1;
			break;
		}
		if (currLoc-m >= 0 && grid[currLoc-m] != '#' && pathLen[currLoc-m] == 1e9) {
			pathLen[currLoc-m] = currDist+1;
			q.push({currLoc-m, currDist+1});
		}
		if (currLoc+m < n*m && grid[currLoc+m] != '#' && pathLen[currLoc+m] == 1e9) {
			pathLen[currLoc+m] = currDist+1;
			q.push({currLoc+m, currDist+1});
		}
		if (currLoc%m-1 >= 0 && grid[currLoc-1] != '#' && pathLen[currLoc-1] == 1e9) {
			pathLen[currLoc-1] = currDist+1;
			q.push({currLoc-1, currDist+1});
		}
		if (currLoc%m+1 < m && grid[currLoc+1] != '#' && pathLen[currLoc+1] == 1e9) {
			pathLen[currLoc+1] = currDist+1;
			q.push({currLoc+1, currDist+1});
		}
	}
	if (!found) {
		cout << "NO";
		return;
	}
	cout << endl;
	cout << "YES" << endl;
	cout << pathLen[A] << endl;
	printPath(grid, A, n, m, pathLen);
}

int main() {
	int n, m; cin>>n>>m;
	string grid;
	for (int i=0; i<n; i++) {
		string temp; cin>>temp;
		grid += temp;
	}
	solve(n, m, grid);
	return 0;
}

