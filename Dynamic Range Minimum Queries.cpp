#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

vector<int> tree;

int f(int node, int l, int r, int ql, int qr, int newVal = -1) {
	if (ql > r || qr < l) return 1e9+1;
	if (ql <= l && qr >= r) {
		if (newVal != -1) tree[node] = newVal;
		return tree[node];
	}
	int mid = (l+r)/2;
	int temp = min(
			f(2*node, l, mid, ql, qr, newVal),
			f(2*node+1, mid+1, r, ql, qr, newVal)
			);
	tree[node] = min(tree[2*node], tree[2*node+1]);
	return temp;
}

int main() {
	int n, q;
	cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	tree.resize(2*n);

	for (int i=0; i<n; i++) tree[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) tree[i] = min(tree[2*i], tree[2*i+1]);

	while (q--) {
		int a, b, c;
		cin>>a>>b>>c;
		if (a == 1) f(1, 0, n-1, b-1, b-1, c);
		else cout << f(1, 0, n-1, b-1, c-1) << endl;
	}
	return 0;
}
