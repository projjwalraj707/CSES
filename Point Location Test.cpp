#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin>>t;
	while (t--) {
		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		const ll val = (y3-y1)*(x2-x1) - (y2-y1)*(x3-x1);
		if (val == 0) cout << "TOUCH";
		else if (val < 0) cout << "RIGHT";
		else cout << "LEFT";
		cout << '\n';
	}
	return 0;
}

