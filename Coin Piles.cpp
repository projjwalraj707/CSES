#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(ll a, ll b) {
	if ((2*a-b)%3 == 0 && 2*a-b >= 0 && (2*b-a)%3 == 0 && 2*b-a >= 0) return 1;
	return 0;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int a, b; cin>>a>>b;
		if (solve(a, b)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}

