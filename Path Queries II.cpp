#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>>
	adj, //stores adjancecy list of the tree
	hier; //hier[node][k] = 2^k th parent of node
vector<int>
	val, //val[i] = value of node i
	level, //level[node] = depth or level of node assuming node 0 to be root
	topOfChain, //topOfChain[node] = top most node of the current chain
	flatten, //node was flatten[node]th node in dfs traversal
	subTreeSize, //subTreeSize[node] = no. of nodes in the subtree of node (including itself)
	segTree; // segTree for chains
 
void dfs(int node = 0, int par = 0, int depth = 0) {
	hier[node][0] = par;
	level[node] = depth;
	for (int& neigh: adj[node]) if (neigh != par) {
		dfs(neigh, node, depth+1);
		subTreeSize[node] += subTreeSize[neigh];
	}
}
 
void HLD(vector<vector<int>>& adj, vector<int>& flatten, vector<int>& topOfChain, vector<int>& subTreeSize, int& id, vector<int>& segTree, vector<int>& val, int node = 0, int par = 0, int currTopOfChain = 0) {
	flatten[node] = id;
	segTree.push_back(val[node]);
	int heavyNeigh = -1;
	topOfChain[node] = currTopOfChain;
	for (int& neigh: adj[node]) if (neigh != par) if (heavyNeigh == -1 || subTreeSize[heavyNeigh] < subTreeSize[neigh]) heavyNeigh = neigh;
	if (heavyNeigh == -1) return; //this is a leaf node
	HLD(adj, flatten, topOfChain, subTreeSize, ++id, segTree, val, heavyNeigh, node, currTopOfChain); //heading to the heavy chain
	for (int& neigh: adj[node]) if (neigh != par && neigh != heavyNeigh) HLD(adj, flatten, topOfChain, subTreeSize, ++id, segTree, val, neigh, node, neigh);
}
 
int findKthPar(int node, int k, vector<vector<int>>& hier) {
	for (int i=17; i>=0; i--) if ((1<<i) & k) node = hier[node][i];
	return node;
}
 
int LCA(int node1, int node2, vector<vector<int>>& hier, vector<int>& level) {
	if (level[node2] < level[node1]) swap(node1, node2);
	node2 = findKthPar(node2, level[node2] - level[node1], hier);
	if (node1 == node2) return node1;
	for (int i=17; i>=0; i--) {
		if (hier[node1][i] == hier[node2][i]) continue;
		node1 = hier[node1][i];
		node2 = hier[node2][i];
	}
	return hier[node1][0];
}
 
int f(int node, int l, int r, int ql, int qr, int newVal, vector<int>& segTree) {
	if (l > qr || r < ql) return -1;
	if (ql <= l && qr >= r) {
		if (newVal != -1) segTree[node] = newVal;
		return segTree[node];
	}
	int mid = (l+r)/2;
	int temp = max(
			f(2*node, l, mid, ql, qr, newVal, segTree),
			f(2*node+1, mid+1, r, ql, qr, newVal, segTree)
		);
	segTree[node] = max(segTree[2*node], segTree[2*node+1]);
	return temp;
}
 
int query(int node1, int node2, int& n, vector<int>& flatten, vector<int>& segTree, vector<int>& level, vector<int>& topOfChain, vector<vector<int>>& hier) { //node2 is guaranteed to be on the path from node1 to the root.
	//case I: node1 and node2 are in the same branch
	if (level[topOfChain[node1]] == level[topOfChain[node2]]) return f(1, 0, n-1, flatten[node2], flatten[node1], -1, segTree);
	
	//case II: The nodes are in different branches
	return max(
			f(1, 0, n-1, flatten[topOfChain[node1]], flatten[node1], -1, segTree),
			query(hier[topOfChain[node1]][0], node2, n, flatten, segTree, level, topOfChain, hier)
		);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin>>n>>q;
	int newN = n;
	while (__builtin_popcount(newN) != 1) newN++;
 
	adj.resize(n);
	hier.resize(n, vector<int>(18));
	val.resize(n);
	level.resize(n);
	topOfChain.resize(n);
	flatten.resize(n);
	subTreeSize.resize(n, 1);
	segTree.resize(newN);
 
	for (int& x: val) cin>>x;
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for (int i=1; i<18; i++) for (int j=1; j<n; j++) hier[j][i] = hier[hier[j][i-1]][i-1];
	int id = 0;
	HLD(adj, flatten, topOfChain, subTreeSize, id, segTree, val);
	while (segTree.size() != 2*newN) segTree.push_back(0);
	/*
	for (int& x: level) cout << x << ' '; cout << endl;
	for (int& x: topOfChain) cout << x << ' '; cout << endl;
	for (int& x: flatten) cout << x << ' '; cout << endl;
	for (int& x: subTreeSize) cout << x << ' '; cout << endl;
	for (int& x: segTree) cout << x << ' '; cout << endl;
	return 0;
	*/
	while (__builtin_popcount(segTree.size()) != 1) segTree.push_back(0);
	for (int i=newN-1; i>=1; i--) segTree[i] = max(segTree[2*i], segTree[2*i+1]);
	while (q--) {
		int type; cin>>type;
		if (type == 1) {
			int s, x; cin>>s>>x; s--;
			f(1, 0, newN-1, flatten[s], flatten[s], x, segTree);
		}
		else {
			int a, b; cin>>a>>b; a--; b--;
			int c = LCA(a, b, hier, level);
			cout << max(
					query(a, c, newN, flatten, segTree, level, topOfChain, hier),
					query(b, c, newN, flatten, segTree, level, topOfChain, hier)
				) << ' ';
		}
	}
	return 0;
}
