#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, x; cin>>n>>x;
	vector<pair<int,int>> arr;
	for (int i=0, temp; i<n; i++) {
		cin>>temp;
		if (temp != x) arr.push_back({temp, i+1});
	}
	sort(arr.begin(), arr.end());
	int s = 0, e = arr.size()-1;
	ll sum;
	while (s < e) {
		sum = arr[s].first + arr[e].first;
		if (sum == x) {
			cout << arr[s].second << " " << arr[e].second;
			return 0;
		}
		else if (sum < x) s++;
		else e--;
	}
	cout << "IMPOSSIBLE";
	return 0;
}

