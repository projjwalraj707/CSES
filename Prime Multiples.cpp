#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ull unsigned long long int
#define ll long long int
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>

int log_(int num) {
	return 31 - __builtin_clz(num); //clz: count leading zero
}

int LOG_(int num) {
	int temp = log_(num);
	if (num == (1<<temp)) return temp;
	return temp+1;
}

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}
void printThis(vi& arr, string name = "") {
	if (name.length()) cout<<"Printing "<<name<<':'<<nl;
	for (int num: arr) cout<<num<<' '; cout<<nl;
	if (name.length()) cout<<"____________\n";
}
void printThis(vvi& arr, string name = "") {
	if (name.length()) cout<<"Printing "<<name<<':'<<nl;
	for (vi& curr: arr) printThis(curr);
	if (name.length()) cout<<"____________\n";
}

ull solve(vector<ull>& arr, ull n, ull k) {
	ull ans = 0;
	ull mask = 1;
	while (mask < (1<<k)) {
		ull divisor = 1;
		ull cnt = 0;
		for (int i=0; i<k; i++) if (mask & (1<<i)) {
			if (divisor > n / arr[i]) { //I copied this condition from internet
					divisor= n + 1;
					break;
			}
			divisor *= arr[i];
			cnt++;
		}
		if (cnt % 2) ans += (n/divisor);
		else ans -= (n/divisor);
		mask++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ull n;
	ull k;
	cin>>n>>k;
	vector<ull> arr(k);
	for (ull& x: arr) cin>>x;
	cout<<solve(arr, n, k)<<nl;
	return 0;
}
