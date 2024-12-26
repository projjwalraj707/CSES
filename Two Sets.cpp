#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

int main() {
	ll n; cin>>n;
	ll sum = (n*(n+1)) >> 1;
	if (sum % 2) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << nl;
	sum = sum >> 1;
	ll curr = 1;
	int mini = 1, maxi = 1;
	while (curr != sum) {
		if (curr < sum) {
			maxi++;
			curr += maxi;
		}
		else if (curr > sum) {
			curr -= mini;
			mini++;
		}
	}
	cout << maxi - mini + 1 << nl;
	for (int i=mini; i<=maxi; i++) cout << i << " "; cout << nl;
	cout << n - maxi + mini - 1 << nl;
	for (int i=1; i<mini; i++) cout << i << " ";
	for (int i=maxi+1; i<=n; i++) cout << i << " "; cout << nl;
	return 0;
}

