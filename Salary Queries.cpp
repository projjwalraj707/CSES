#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
int MAXI = 1e6;
int WINDOW = 1000;

vector<int> tree;

int f(int node, int l, int r, int ql, int qr, int change = 0) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		tree[node] += change;
		return tree[node];
	}
	int mid = (l+r)/2;
	int ans = f(2*node, l, mid, ql, qr, change) + f(2*node+1, mid+1, r, ql, qr, change);
	tree[node] = tree[2*node] + tree[2*node+1];
	return ans;
}

int main() {
	int n, q; cin>>n>>q;
	unordered_map<int,int> mp;
	while (__builtin_popcount(MAXI) != 1) MAXI++;
	tree.resize(2*MAXI);
	vector<int> p(n);
	for (int& x: p) {
		cin>>x;

		tree[MAXI + (x/WINDOW)]++;
		mp[x]++;
	}
	for (int i=MAXI-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];

	while (q--) {
		char type; cin>>type;
		if (type == '!') {
			int k, x; cin>>k>>x;
			int oldSalary = p[k-1];
			p[k-1] = x;
			if (mp[oldSalary] == 1) mp.erase(oldSalary);
			else mp[oldSalary]--;
			mp[x]++;
			f(1, 0, MAXI-1, oldSalary/WINDOW, oldSalary/WINDOW, -1);
			f(1, 0, MAXI-1, x/WINDOW, x/WINDOW, 1);
		}
		else {
			int a, b; cin>>a>>b;
			if (b < WINDOW) {
				int ans = 0;
				for (int i=a; i<=b; i++) ans += mp[i]; 
				cout << ans << nl;
			}
			else {
				a--;
				int ans = f(1, 0, MAXI-1, 0, (b-b%WINDOW)/WINDOW-1);
				for (int i=b-b%WINDOW; i<=b; i++) ans += mp[i];
				if (a>=WINDOW) ans -= f(1, 0, MAXI-1, 0, (a-a%WINDOW)/WINDOW-1);
				for (int i=a-a%WINDOW; i<=a; i++) ans -= mp[i];
				cout << ans << nl;
			}
		}
	}
	return 0;
}

