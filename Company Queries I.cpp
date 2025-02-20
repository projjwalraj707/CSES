#include <bits/stdc++.h>
using namespace std;

int findAns(vector<vector<int>>& boss, int ans, int& k) {
	int ind = 0;
	while ((1<<ind) <= k) {
		if ((1<<ind) & k) ans = boss[ans][ind];
		ind++;
		if (ans == -1) return -2;
	}
	return ans;
}

int main() {
	int n, q; cin>>n>>q;
	vector<vector<int>> boss(n, vector<int>(18, -1));
	for (int i=1, e; i<=n-1; i++) {
		cin >> e;
		e--;
		boss[i][0] = e;
	}
	for (int i=1; i<18; i++) for (int j=1; j<n; j++) 
			if (boss[j][i-1] != -1) boss[j][i] = boss[boss[j][i-1]][i-1];
	while (q--) {
		int x, k; cin>>x>>k;
		x--;
		cout << findAns(boss, x, k) + 1<< '\n';
	}
	return 0;
}

