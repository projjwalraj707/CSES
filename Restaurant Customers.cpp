#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<pair<int,int>> arr;
	for (int i=0, temp; i<n; i++) {
		cin>>temp;
		arr.push_back({temp, 1});
		cin>>temp;
		arr.push_back({temp, -1});
	}
	sort(arr.begin(), arr.end());
	int curr = 0;
	int maxi = 0;
	for (int i=0; i<arr.size(); i++) {
		curr += arr[i].second;
		maxi = max(maxi, curr);
	}
	cout << maxi << endl;
	return 0;
}

