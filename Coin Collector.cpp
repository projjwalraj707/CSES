#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfsTopo(int node, vector<bool>& vis, vector<int>& topo, vector<vector<int>>& adj) {
	if (vis[node]) return;
	vis[node] = 1;
	for (int& neigh: adj[node]) dfsTopo(neigh, vis, topo, adj);
	topo.push_back(node);
}

void dfsSCCID(int node, vector<vector<int>>& adj, int& curr, vector<int>& SCCID, vector<int>& coins, ll& sum) {
	if (SCCID[node] != -1) return;
	SCCID[node] = curr;
	sum += coins[node];
	for (int& neigh: adj[node]) dfsSCCID(neigh, adj, curr, SCCID, coins, sum);
}

void dfsAdjSCC(int node, vector<int>&SCCID, vector<bool>& vis, vector<unordered_set<int>>& adjSCC, vector<vector<int>>& adj) {
	if (!vis[node]) return;
	vis[node] = 0;
	for (int& neigh: adj[node])
		if (SCCID[neigh] == SCCID[node]) dfsAdjSCC(neigh, SCCID, vis, adjSCC, adj);
		else adjSCC[SCCID[node]].insert(SCCID[neigh]);
}

ll dfsDP(int node, vector<ll>& SCCVal, vector<unordered_set<int>>& adjSCC, vector<ll>& dp) {
	if (dp[node] != -1) return dp[node];
	dp[node] = 0;
	for (int neigh: adjSCC[node]) dp[node] = max(dp[node], dfsDP(neigh, SCCVal, adjSCC, dp));
	dp[node] += SCCVal[node];
	return dp[node];
}

ll solve(int& n, int& m, vector<int>& coins, vector<vector<int>>& adj, vector<vector<int>>& revAdj) {
	vector<bool> vis(n);
	vector<int> topo,//stores the nodes in topological order
		SCCID(n, -1); //SCCID[i]: unique identifier of the SCC ith node belongs to
	vector<ll> SCCVal; //SCCVal[i]: sum of all the coins present in ith SCC
	for (int i=0; i<n; i++) if (!vis[i]) dfsTopo(i, vis, topo, adj);
	int curr = 0;
	for (int i=n-1; i>=0; i--) if (SCCID[topo[i]] == -1) {
		SCCVal.push_back(0);
		dfsSCCID(topo[i], revAdj, curr, SCCID, coins, SCCVal[SCCVal.size()-1]);
		curr++;
	}
	vector<unordered_set<int>> adjSCC(curr);
	for (int i=0; i<n; i++) if (vis[i]) dfsAdjSCC(i, SCCID, vis, adjSCC, adj);
	vector<ll> dp(curr, -1);
	for (int i=0; i<curr; i++) if (dp[i] == -1) dfsDP(i, SCCVal, adjSCC, dp);
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int n, m; cin>>n>>m;
	vector<int> coins(n);
	for (int& x: coins) cin>>x;
	vector<vector<int>> adj(n), revAdj(n);
	for (int i=0, a,b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		revAdj[b].push_back(a);
	}
	cout << solve(n, m, coins, adj, revAdj);
	return 0;
}

