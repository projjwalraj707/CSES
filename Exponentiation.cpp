#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
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

ll solve(ll a, ll b) {
	ll ans = 1;
	ll temp = a;
	while (b) {
		if (b&1) ans = (ans*temp)%MOD;
		b = b>>1;
		temp = (temp*temp)%MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b; cin>>n;
	while (n--) {
		cin>>a>>b;
		cout<<solve(a, b)<<nl;
	}
	return 0;
}
