//not omo
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int ans = 0;
		for (int i=0, temp; i<n; i++) {
			cin >> temp;
			if (i%2) ans ^= temp;
		}
		if (ans) cout << "first";
		else cout << "second";
		cout << endl;
	}
	return 0;
}

