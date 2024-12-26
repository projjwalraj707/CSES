//OMO
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

vector<pair<string,string>> solve(int n, string start, string middle, string finl) {
	if (n == 1) return {{start, finl}};
	vector<pair<string, string>> ans = solve(n-1, start, finl, middle);
	ans.push_back({start, finl});
	vector<pair<string, string>> temp = solve(n-1, finl, start, middle);
	for (int i=temp.size()-1; i>=0; i--) ans.push_back({temp[i].second, temp[i].first});
	return ans;
}

int main() {
	int n; cin>>n;
	vector<pair<string, string>> ans = solve(n, "1", "2", "3");
	cout << ans.size() << nl;
	for (pair<string, string>& p: ans) cout << p.first << " " << p.second << nl;
	return 0;
}
