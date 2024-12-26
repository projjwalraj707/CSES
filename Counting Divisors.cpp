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
int maxi = 1e6;
vi arr(maxi+1, -1);

int findMaxPow(int j, int i) {
	int ans = 0;
	while (j%i == 0) {
		ans++;
		j /= i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	arr[1] = 1;
	for (int i=2; i<=maxi; i++)
		if (arr[i] == -1) {
			arr[i] = 2;
			for (int j=i*2; j<=maxi; j += i) {
				int maxPow = findMaxPow(j, i);
				if (arr[j] == -1) arr[j] = maxPow+1;
				else arr[j] *= (maxPow+1);
			}
		}
	int n; cin>>n;
	while (n--) {
		int x; cin>>x;
		cout<<arr[x]<<nl;
	}
	return 0;
}
