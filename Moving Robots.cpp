//not omo
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int dirI[] = {-1, 0, 1, 0};
int dirJ[] = {0, 1, 0, -1};

vector<vector<double>> makeTurn(vector<vector<double>>& prob) {
	vector<vector<double>> ans(8, vector<double>(8, 0));
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (prob[i][j] != 0) {
				int cnt = 0;
				for (int dir = 0; dir<4; dir++) {
					if (i+dirI[dir] >=0 && i+dirI[dir] < 8 && j+dirJ[dir] >=0 && j+dirJ[dir] < 8) cnt++;
				}
				for (int dir = 0; dir<4; dir++) {
					if (i+dirI[dir] >=0 && i+dirI[dir] < 8 && j+dirJ[dir] >=0 && j+dirJ[dir] < 8) ans[i+dirI[dir]][j+dirJ[dir]] += prob[i][j]/cnt;
				}
			}
		}
	}
	return ans;
}

double solve(int k) {
	vector<vector<double>> ans(8, vector<double> (8, 1));
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			vector<vector<double>> prob(8, vector<double>(8));
			prob[i][j] = 1;
			for (int turn = 0; turn < k; turn++) {
				prob = makeTurn(prob);
			}
			for (int x=0; x<8; x++) {
				for (int y=0; y<8; y++) {
					ans[x][y] *= (1 - prob[x][y]);
				}
			}
		}
	}
	double finalAns = 0;
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			finalAns += ans[i][j];
		}
	}
	return finalAns;
}

int main() {
	int k; cin>>k;
	cout << fixed << setprecision(6) << solve(k) << nl;
	return 0;
}

