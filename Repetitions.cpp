#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin>>str;
	char last = 'z';
	int ans = 0;
	int curr = 0;
	for (char c: str) {
		if (c != last) {
			last = c;
			ans = max(ans, curr);
			curr = 0;
		}
		curr++;
	}
	ans = max(ans, curr);
	cout << ans; 
	return 0;
}

