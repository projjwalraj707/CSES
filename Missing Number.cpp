#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int ans = 0;
	for (int i=0, temp; i<n-1; i++) {
		cin>>temp;
		ans ^= temp;
		ans ^= (i+1);
	}
	ans ^= (n);
	cout << ans;
	return 0;
}

