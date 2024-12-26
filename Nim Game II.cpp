#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int nimber = 0;
		for (int i=0, temp; i<n; i++) {
			cin >> temp;
			nimber = nimber ^ (temp % 4);
		}
		if (nimber == 0) cout << "second";
		else cout << "first";
		cout << endl;
	}

	return 0;
}

