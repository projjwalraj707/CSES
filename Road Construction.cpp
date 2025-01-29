#include <bits/stdc++.h>
using namespace std;
vector<int> par;

int findPar(int node) {
	if (par[node] == node) return node;
	return par[node] = findPar(par[node]);
}

int main() {
	int n, m; cin>>n>>m;
	for (int i=0; i<n; i++) par.push_back(i);
	vector<int> compSize(n, 1);
	int largest = 1, components = n;
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		if (findPar(a) != findPar(b)) {
			largest = max(largest, compSize[findPar(a)] + compSize[findPar(b)]);
			compSize[findPar(a)] += compSize[findPar(b)];
			par[findPar(b)] = findPar(a);
			components--;
		}
		cout << components << ' ' << largest << '\n';
	}
	return 0;
}

