#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin>>str;
	int n = str.length();
	vector<int> piTable(n);
	int s = 0, e = 1;
	while (e < n) {
		if (str[s] == str[e]) {
			piTable[e] = ++s;
			e++;
		}
		else if (s == 0) e++;
		else s = piTable[s-1];
	}
	int ind = n-1;
	vector<int> ans;
	while (ind > 0 && piTable[ind] != 0) {
		ans.push_back(piTable[ind]);
		ind = piTable[ind]-1;
	}
	sort(ans.begin(), ans.end());
	for (int& x: ans) cout << x << ' ';
	return 0;
}

