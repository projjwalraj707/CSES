#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
vector<ll> rangeSumTree;
vector<ll> rangeMaxTree;
int n;

ll fSum(int node, int l, int r, int ql, int qr, int newVal = 0) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		if (newVal != 0) rangeSumTree[node] = newVal;
		return rangeSumTree[node];
	}
	int mid = (l+r)/2;
	ll temp = fSum(2*node, l, mid, ql, qr, newVal) + fSum(2*node+1, mid+1, r, ql, qr, newVal);
	rangeSumTree[node] = rangeSumTree[2*node] + rangeSumTree[2*node+1];
	return temp;
}

void updateMax(int node, int newVal) {
	if (newVal < 0) rangeMaxTree[node] = 0;
	else rangeMaxTree[node] = newVal;
	while (node > 1) {
		node = node >> 1;
		rangeMaxTree[node] = max(rangeMaxTree[2*node], rangeSumTree[2*node] + rangeMaxTree[2*node+1]);
	}
}

ll findMax(int node, int l, int r, int ql, int qr) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		ll ans = rangeMaxTree[node];
		if (ql < l) ans += fSum(1, 0, n-1, ql, l-1);
		return ans;
	}
	int mid = (l+r)/2;
	return max(findMax(2*node, l, mid, ql, qr), findMax(2*node+1, mid+1, r, ql, qr));
}

int main() {
	int q; cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	
	//build rangeSumTree
	rangeSumTree.resize(2*n);
	for (int i=0; i<n; i++) rangeSumTree[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) rangeSumTree[i] = rangeSumTree[2*i] + rangeSumTree[2*i+1];

	//build rangeMaxTree
	rangeMaxTree.resize(2*n);
	for (int i=0; i<n; i++) if (arr[i] > 0) rangeMaxTree[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) rangeMaxTree[i] = max(rangeMaxTree[2*i], rangeSumTree[2*i] + rangeMaxTree[2*i+1]);

	while (q--) {
		int type; cin>>type;
		if (type == 1) {
			int k, u; cin>>k>>u;
			fSum(1, 0, n-1, k-1, k-1, u);
			updateMax(n+k-1, u);
		}
		else {
			int a, b; cin>>a>>b;
			cout << findMax(1, 0, n-1, a-1, b-1) << nl;
		}
	}
	return 0;
}

