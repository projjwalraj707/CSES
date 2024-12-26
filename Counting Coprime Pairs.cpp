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

vi divisors(1e6+1), cntDivisors(1e6+1);

void sieveOfErat() {
	for (int i=2; i<=1e6; i++) if (divisors[i] == 0) for (int j=2*i; j<=1e6; j += i) divisors[j] = i;
}

void findFactors(int num, vi& factors) {
	if (num == 1) return;
	int f = divisors[num];
	if (f == 0) f = num;
	factors.push_back(f);
	while (num % f == 0) num /= f;
	findFactors(num, factors);
}

void updateCntDivisors(vi& factors) {
	int mask = 1;
	int noOfFact = factors.size();
	while (mask < (1<<noOfFact)) {
		ll prod = 1;
		for (int i=0; i<noOfFact; i++) if (mask & (1<<i)) prod *= factors[i];
		cntDivisors[prod]++;
		mask++;
	}
}

ll help(vi& factors) {
	ll ans = 0;
	int mask = 1;
	int size = factors.size();
	while (mask < (1<<size)) {
		int cnt = 0;
		ll prod = 1;
		for (int i=0; i<size; i++) if (mask & (1<<i)) {
			prod *= factors[i];
			cnt++;
		}
		if (cnt % 2) ans += cntDivisors[prod];
		else ans -= cntDivisors[prod];
		mask++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin>>n;
	vi arr(n);
	for (int& x: arr) cin>>x;
	sieveOfErat();
	ll ans = 0;
	for (int i=0; i<n; i++) {
		vi factors;
		findFactors(arr[i], factors);
		ans += i - help(factors);
		updateCntDivisors(factors);
	}
	cout<<ans<<nl;
	return 0;
}
