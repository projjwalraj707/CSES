// I first tried to solve it using multi set but the solution went too long so I switched to map and it was much easier to solve.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& ans, vector<int>& arr, int& n, int& k) {
	if (k == 1) {
		ans = arr;
		return;
	}
	ans.resize(n-k+1);
	map<int,int> mp;
	for (int i=0; i<k; i++) mp[arr[i]]++;
	auto medItr = mp.begin();
	int cnt = medItr->second;;
	while (cnt < (k+1)/2) {
		medItr++;
		cnt += medItr->second;
	}
	ans[0] = medItr->first;
	for (int i=k; i<n; i++) {
		//remove the (i-k)th element
		if (arr[i-k] <= medItr->first) cnt--;
		mp[arr[i-k]]--;
		while (cnt - medItr->second >= (k+1)/2) {
			cnt -= medItr->second;
			medItr--;
		}
		while (cnt < (k+1)/2) {
			medItr++;
			cnt += medItr->second;
		}
		if (mp[arr[i-k]] == 0) mp.erase(arr[i-k]);

		//add the current ith element
		if (arr[i] <= medItr->first) cnt++;
		mp[arr[i]]++;
		while (cnt - medItr->second >= (k+1)/2) {
			cnt -= medItr->second;
			medItr--;
		}
		while (cnt < (k+1)/2) {
			medItr++;
			cnt += medItr->second;
		}
		ans[i-k+1] = medItr->first;
	}

}
/*
void solve(vector<int>& ans, vector<int>& arr, int& n, int& k) {
	ans.resize(n-k+1);
	multi_set<int> st;
	for (int i=0; i<k; i++) st.insert(arr[i]);
	auto medItr = st.begin();
	for (int i=2; i<k; i+=2) medItr++;
	ans[0] = *medItr;
	for (int i=k; i<n; i++) {
		if ((arr[i-k] < *medItr && arr[i] < *medItr) || (arr[i-k] > *medItr && arr[i] > *medItr)) {
			st.insert(arr[i]);
			st.remove(arr[i-k]);
		}
		else if (arr[i-k] < *medItr && arr[i] > *medItr) {
			st.insert(arr[i]);
			st.remove(arr[i-k]);
			medItr++;
		}
		else if (arr[i-k] > *medItr && arr[i] < *medItr) {
			st.insert(arr[i]);
			st.remove(arr[i-k]);
			medItr--;
		}
		else if (arr[i-k] == *medItr && arr[i] == arr[i-k]) continue;
		else if (arr[i-k] == *medItr) {
			if (k == 1) {
				st.insert(arr[i]);
				st.remove(arr[i-k]);
				medItr = st.begin();
			}
			else if (arr[i] < *medItr) {
				medItr++;
				st.insert(arr[i]);
				st.remove(arr[i-k]);
				medItr--;
			}
			else {
				medItr--;
				st.insert(arr[i]);
				st.remove(arr[i-k]);
				medItr++;
			}
		}
		else {
			if (arr[i-k] < *medItr) {
				st.insert(arr[i]);
				st.remove(arr[i-k]);
				medItr++;
			}
			else {
				
			}
		}
		ans[i-k+1] = *medItr;
	}
}
*/

int main() {
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	vector<int> ans;
	solve(ans, arr, n, k);
	for (int& x: ans) cout << x << ' ';
	return 0;
}

