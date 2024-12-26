#include <bits/stdc++.h>
using namespace std;

string solve(string& str) {
	vector<int> freq(26);
	for (char c: str) freq[c-'A']++;
	int odd = 0;
	string ans;
	for (int i=0; i<26; i++) if (freq[i]%2) {
		odd++;
		ans = string(freq[i], 'A' + i);
	}
	if (str.length()%2 && odd != 1) return "NO SOLUTION";
	if (str.length()%2 == 0 && odd != 0) return "NO SOLUTION";
	for (int i=0; i<26; i++) if (freq[i]%2==0) {
		ans = string(freq[i]/2, 'A' + i) + ans + string(freq[i]>>1, 'A' + i);
	}
	return ans;
}

int main() {
	string str; cin>>str;
	cout << solve(str) << endl;
	return 0;
}

