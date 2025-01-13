#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	vector<int> coins(n);
	for (int& i: coins) cin>>i;
	set<int> st = {coins[0]};
	for (int i=1; i<n; i++) {
		vector<int> temp;
		for (int x: st) temp.push_back(x+coins[i]);
		for (int x: temp) st.insert(x);
		st.insert(coins[i]);
	}
	cout << st.size() << "\n";
	for (int x: st) cout << x << ' ';
	return 0;
}

