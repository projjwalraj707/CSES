#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION";
		return 0;
	}
	if (n == 4) {
		cout << "2 4 1 3";
		return 0;
	}
	vector<int> arr(n);
	int cnt = 0;
	for (int i=0; i<n; i+=2) {
		cnt++;
		arr[i] = cnt;
	}
	for (int i=1; i<n; i+=2) {
		cnt++;
		arr[i] = cnt;
	}
	for (int& x: arr) cout << x << ' ';
	return 0;
}

