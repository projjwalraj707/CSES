#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int xorVal = 0;
		for (int i=0, temp; i<n; i++) {
			cin >> temp;
			xorVal = xorVal ^ temp;
		}
		if (xorVal == 0) cout << "second";
		else cout << "first";
		cout << '\n';
	}
	return 0;
}
