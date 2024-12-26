#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int n) {
	if (n == 1) return {"0", "1"};
	vector<string> prev = solve(n-1);
	vector<string> ans;
	for (int i=0; i<prev.size(); i++) ans.push_back("0" + prev[i]);
	for (int i=prev.size()-1; i>=0; i--) ans.push_back("1" + prev[i]);
	return ans;
}

int main() {
	int n; cin>>n;
	vector<string> ans = solve(n);
	for (string str: ans) cout << str << endl;
	return 0;
}

