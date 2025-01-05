#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	ll sum = accumulate(arr.begin(), arr.end(), (ll)0);
	int maxi = *max_element(arr.begin(), arr.end());
	ll sumExceptLast = sum-maxi;
	if (sumExceptLast < maxi) cout << maxi - sumExceptLast + sum;
	else cout << sum;
	cout << "\n";
	return 0;
}

