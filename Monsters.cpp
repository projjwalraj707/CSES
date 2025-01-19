#include <bits/stdc++.h>
using namespace std;
int a[] = {-1, 0, 1, 0};
int b[] = {0, 1, 0, -1};
char dir[] = {'D', 'L', 'U', 'R'};

void monsterBFS(vector<vector<int>>& monsters, int& n, int& m, vector<string>& grid, queue<pair<int, int>>& q) {
	while (q.size()) {
		int currI = q.front().first / m, currJ = q.front().first % m, currDist = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			if (currI + a[i] >=0 && currI + a[i] < n && currJ + b[i] >=0 && currJ + b[i] < m && grid[currI+a[i]][currJ+b[i]] != '#' &&  monsters[currI+a[i]][currJ+b[i]] > monsters[currI][currJ] + 1) {
				monsters[currI+a[i]][currJ+b[i]] = currDist + 1;
				q.push({(currI+a[i])*m + currJ+b[i], currDist+1});
			}
		}
	}
}

pair<int,int> manBFS(vector<string>& grid, int& n, int& m, pair<int,int>& A, vector<vector<int>>& monsters, vector<vector<int>>& man) {
	man[A.first][A.second] = 0;
	queue<pair<int,int>> q;
	q.push({A.first*m+A.second, 0});
	while (q.size()) {
		int currI = q.front().first / m, currJ = q.front().first % m, currDist = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			if (currI + a[i] >=0 && currI + a[i] < n && currJ + b[i] >=0 && currJ + b[i] < m) {
				if (grid[currI+a[i]][currJ+b[i]] != '#' && monsters[currI+a[i]][currJ+b[i]] > currDist + 1 && man[currI+a[i]][currJ+b[i]] == 1e9) {
					q.push({(currI+a[i])*m + currJ+b[i], currDist+1});
					man[currI+a[i]][currJ+b[i]] = currDist+1;
				}
			}
			else return {currI, currJ};
		}
	}
	return {-1, -1};
}

void dfs(int x, int y, int& n, int& m, vector<vector<int>>& man, string& path) {
	if (man[x][y] == 0) return;
	int mini = 1e9;
	for (int i=0; i<4; i++) if (x+a[i] >= 0 && x+a[i] < n && y+b[i] >= 0 && y+b[i] < m) mini = min(mini, man[x+a[i]][y+b[i]]);
	for (int i=0; i<4; i++) if (x+a[i] >= 0 && x+a[i] < n && y+b[i] >= 0 && y+b[i] < m) {
		if (man[x+a[i]][y+b[i]] == mini) {
			dfs(x+a[i], y+b[i], n, m, man, path);
			path.push_back(dir[i]);
			return;
		}
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<string> grid(n);
	for (string& str: grid) cin>>str;
	vector<vector<int>> monsters(n, vector<int> (m, 1e9));
	vector<vector<int>> man(n, vector<int> (m, 1e9));
	pair<int,int> A;
	queue<pair<int,int>> q;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (grid[i][j] == 'M') {q.push({i*m+j, 0}); monsters[i][j] = 0;} else if (grid[i][j] == 'A') A = {i, j};
	monsterBFS(monsters, n, m, grid, q);
	pair<int,int> ans = manBFS(grid, n, m, A, monsters, man);
	if (ans.first == -1) {cout << "NO"; return 0;}
	string path;
	dfs(ans.first, ans.second, n, m, man, path);
	cout << "YES" << '\n' << path.size() << '\n';
	cout << path << endl;
	return 0;
}
