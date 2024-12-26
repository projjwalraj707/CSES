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

ull MOD = 1e9+7;

ll modExp(ll p, ll k) {
	ll ans = 1;
	int mask = 1;
	ll temp = p;
	while (mask <= k) {
		if (mask & k) ans = (ans * temp) % MOD;
		temp = (temp * temp) % MOD;
		mask = mask << 1;
	}
	return ans;
}

ll modInv(ll num, ll M = MOD) {
	return modExp(num, M-2);
}

ll noOfDivisors(vector<pair<int,int>>& factors) {
	ll ans = 1;
	for (pair<int,int>& f: factors) ans = (ans * (f.second+1))%MOD;
	return ans;
}

ll sumOfDivisors(vector<pair<int,int>>& factors) {
	ll ans = 1;
	for (pair<int,int>& f: factors) {
		ans = (ans * (modExp(f.first, f.second+1) + MOD - 1)%MOD)%MOD;
		ans = (ans * modInv(f.first-1))%MOD;
	}
	return ans;
}

ll prodOfDivisors(vector<pair<int,int>>& factors) {
	ull ans = 1;
	ull power = 1;
	bool odd = 0;
	for (pair<ull, ull> f: factors) {
		if (odd || f.second%2 == 0) power = (power * (f.second+1))%(MOD-1);
		else {
			odd = 1;
			power = (power * ((f.second+1)/2))%(MOD-1);
		}
	}
	for (pair<ull, ull> f: factors) {
		ull newPower = power;
		if (odd) newPower = (newPower * f.second)%(MOD-1);
		else newPower = (newPower * f.second/2)%(MOD-1);
		ans = (ans * modExp(f.first, newPower))%MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin>>n;
	vector<pair<int,int>> factors;
	for (int i=0; i<n; i++) {
		int x, k; cin>>x>>k;
		factors.push_back({x, k});
	}
	cout << noOfDivisors(factors) << " " <<	sumOfDivisors(factors) << " " << prodOfDivisors(factors) << nl;
	return 0;
}
