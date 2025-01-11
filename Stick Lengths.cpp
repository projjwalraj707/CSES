#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll findCost(vector<int>& p, int mid) {
	ll ans = 0;
	for (int i=0; i<p.size(); i++) ans += abs(p[i] - mid);
	return ans;
}
 
ll solve(vector<int>& p) {
	ll mini = *min_element(p.begin(), p.end());
	ll maxi = *max_element(p.begin(), p.end());
	while (1) {
		ll mid = (mini + maxi)/2;
		ll cost = findCost(p, mid);
		if (cost <= findCost(p, mid+1) && cost < findCost(p, mid-1)) return cost;
		if (cost > findCost(p, mid+1)) mini = mid+1;
		else maxi = mid;
	}
	return -1;
}

ll solve2(vector<int>& p) {
	sort(p.begin(), p.end());
	int median = p[p.size()/2];
	ll ans = 0;
	for (int& x: p) ans += abs(x-median);
	return ans;
}
 
int main() {
	int n; cin>>n;
	vector<int> p(n);
	for (int& x: p) cin>>x;
	cout << solve2(p);
	return 0;
}
