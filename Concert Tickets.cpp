#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin>>n>>m;
	map<int, int> mp;
	for (int i=0, temp; i<n; i++) {
		cin>> temp;
		mp[0-temp]++;
	}
	for (int i=0, temp; i<m; i++) {
		cin>>temp;
		temp *= -1;
		auto ans = mp.lower_bound(temp);
		if (ans == mp.end()) cout << -1;
		else {
			cout << 0-(*ans).first;
			if (mp[(*ans).first] > 1) mp[(*ans).first]--;
			else mp.erase(ans);
		}
		cout << "\n";
	}
	return 0;
}

