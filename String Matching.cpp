#include <bits/stdc++.h>
using namespace std;

void constructPiTable(string& str, int& n, vector<int>& piTable) {
	if (str.length() == 1) return;
	int s = 0, e = 1;
	while (e < n) {
		if (str[s] == str[e]) {
			s++;
			piTable[e] = s;
			e++;
		}
		else if (s == 0) {
			piTable[e] = 0;
			e++;
		}
		else s = piTable[s-1];
	}
}

void solve(string& str, string& pattern, int& n, int& m, vector<int>& piTable, int& ans) {
	int itr1 = 0, itr2 = 0;
	while (itr1 < n) {
		if (str[itr1] == pattern[itr2]) {
			itr1++;
			itr2++;
			if (itr2 == m) {
				itr2 = piTable.back();
				ans++;
			}
		}
		else if (itr2 == 0) itr1++;
		else itr2 = piTable[itr2-1];
	}
}

int main() {
	string str, pattern;
	cin>>str>>pattern;
	int n = str.length(), m = pattern.length();
		
	vector<int> piTable(m);
	constructPiTable(pattern, m, piTable);
	int ans = 0;
	for (int i: piTable) cout << i << ' '; return 0;
	solve(str, pattern, n, m, piTable, ans);
	cout << ans;
	return 0;
}
