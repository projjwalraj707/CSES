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

void findFactors(int num, vi& factors, vi& primes) {
	while (num != 1) {
		int curr = (primes[num] == -1 ? num : primes[num]);
		factors.push_back(curr);
		while (num%curr == 0) num /= curr;
	}
}

void produceComponents(unordered_set<int>& components, int num, vi& factors, int currNum = 1, int currInd = 0) {
	if (num % currNum) return;
	if (currInd == factors.size()) return;
	components.insert(currNum);
	produceComponents(components, num, factors, currNum, currInd+1);
	produceComponents(components, num, factors, currNum*factors[currInd], currInd);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin>>n;
	unordered_set<int> st;
	vi arr(n);
	vi primes(1e6+1, -1);
	for (int i=2; i<=1e6; i++)
		if (primes[i] == -1)
			for (int j=i*2; j<=1e6; j += i)
				if (primes[j] == -1) primes[j] = i;
	int ans = 1;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		vi factors;
		findFactors(temp, factors, primes);
		unordered_set<int> components;
		produceComponents(components, temp, factors);
		for (int comp: components) {
			if (st.count(comp)) ans = max(ans, comp);
			else st.insert(comp);
		}
	}
	cout<<ans<<nl;
	return 0;
}
