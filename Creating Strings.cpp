#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

vector<string> solve(vector<int>& freq, int cnt) {
	if (cnt == 1) for (int i=0; i<26; i++) if (freq[i] != 0) return {string(freq[i], 'a' + i)};
	vector<string> ans;
	for (int i=0; i<26; i++) {
		if (freq[i] == 0) continue;
		freq[i]--;
		vector<string> temp = solve(freq, cnt - (freq[i] == 0));
		for (string str: temp) ans.push_back(string(1, 'a' + i) + str);
		freq[i]++;
	}
	return ans;
}

int main() {
	string str; cin>>str;
	int cnt = 0;
	vector<int> freq(26);
	for (char c: str) freq[c - 'a']++;
	for (int x: freq) if (x != 0) cnt++;
	vector<string> ans = solve(freq, cnt);
	cout << ans.size() << nl;
	for (string temp: ans) cout << temp << nl;
	return 0;
}

