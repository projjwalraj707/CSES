#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

vector<ll> treeSum, treeLeftMax, treeRightMax, treeAns;

void f(int node, int l, int r, int ql, int qr, int newVal) {
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		treeSum[node] = newVal;
		if (newVal > 0) treeRightMax[node] = treeLeftMax[node] = treeAns[node] = newVal;
		else treeRightMax[node] = treeLeftMax[node] = treeAns[node] = 0;
		return;
	}
	int mid = (l+r)/2;
	f(2*node, l, mid, ql, qr, newVal);
	f(2*node+1, mid+1, r, ql, qr, newVal);
	treeSum[node] = treeSum[2*node] + treeSum[2*node+1];
	treeLeftMax[node] = max(treeLeftMax[2*node+1], treeLeftMax[2*node] + treeSum[2*node+1]);
	treeRightMax[node] = max(treeRightMax[2*node], treeRightMax[2*node+1] + treeSum[2*node]);
	treeAns[node] = max(treeAns[2*node], max(treeAns[2*node+1], treeLeftMax[2*node] + treeRightMax[2*node+1]));
}

ll query(int node, int l, int r, int ql, int qr) {
	if (ql > r || qr  < l) return 0;
	if (ql <= l && qr >= r) return treeAns[node];
	int mid = (l+r)/2;
	return max(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
}

int main() {
	int n, m; cin>>n>>m;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();

	//build treeSum
	treeSum.resize(2*n);
	for (int i=0; i<n; i++) treeSum[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) treeSum[i] = treeSum[2*i] + treeSum[2*i+1];

	//build treeLeftMax
	treeLeftMax.resize(2*n);
	for (int i=0; i<n; i++) if(arr[i] > 0) treeLeftMax[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) treeLeftMax[i] = max(treeLeftMax[2*i+1], treeLeftMax[2*i]+treeSum[2*i+1]);

	//build treeRightMax
	treeRightMax.resize(2*n);
	for (int i=0; i<n; i++) if (arr[i] > 0) treeRightMax[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) treeRightMax[i] = max(treeRightMax[2*i], treeRightMax[2*i+1] + treeSum[2*i]);

	//build treeAns
	treeAns.resize(2*n);
	for (int i=0; i<n; i++) if (arr[i] > 0) treeAns[n+i] = arr[i];
	for (int i=n-1; i>=1; i--) treeAns[i] = max(treeAns[2*i], max(treeAns[2*i+1], treeLeftMax[2*i] + treeRightMax[2*i+1]));

	while (m--) {
		int k, x; cin>>k>>x;
		f(1, 0, n-1, k-1, k-1, x);
		cout << treeAns[1] << nl;
	}
	return 0;
}

