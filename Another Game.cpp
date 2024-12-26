#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool isOdd = 0;
		for (int i=0, temp; i<n; i++) {
			cin >> temp;
			isOdd = isOdd || (temp%2);
		}
		if (isOdd) cout << "first";
		else cout << "second";
		cout << endl;
	}
	return 0;
}

