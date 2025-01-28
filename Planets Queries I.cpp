#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin>>n>>q;
	vector<int> t(n);
	for (int& x: t) cin>>x;
	vector<vector<int>> child(n, vector<int>(30));
	for (int i=0; i<n; i++) child[i][0] = t[i]-1;
	for (int j=1; j<30; j++) for (int i=0; i<n; i++) child[i][j] = child[child[i][j-1]][j-1];
	while (q--) {
		int x, k; cin>>x>>k;
		x--;
		int ind = 0;
		while ((1<<ind) <= k) {
			if ((1<<ind) & k) x = child[x][ind];
			ind++;
		}
		cout << x + 1 << ' ';
	}
	return 0;
}
