#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string& str) {
	int n = str.length();
	vector<int> ans(n);
	int s = 0, e = 1;
	while (e < n) {
		if (str[s] == str[e]) ans[e++] = ++s;
		else if (s != 0) s = ans[s-1];
		else e++;
	}
	return ans;
}

vector<int> Z_Func(string& str) {
	int n = str.size();
	vector<int> ans(n);
	int s = 0, e = 0;
	for (int i=1; i<n; i++) {
		if (i < e) ans[i] = min(ans[i-s], e-i);
		while (i+ans[i] < n && str[ans[i]] == str[i+ans[i]]) ans[i]++;
		if (i+ans[i] > e) {
			s = i;
			e = i+ans[i];
		}
	}
	return ans;
}

int main() {
	string str; cin>>str;
	for (int x: Z_Func(str)) cout << x << ' '; cout << '\n';
	for (int x:   KMP(str)) cout << x << ' '; cout << '\n';
	return 0;
}

