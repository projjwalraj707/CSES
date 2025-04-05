#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll crossProd(ll x1, ll y1, ll x2, ll y2) {
	if (x1 * y2 < x2 * y1) return -1;
	if (x1 * y2 > x2 * y1) return 1;
	return 0;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if (crossProd(x2-x1, y2-y1, x3-x1, y3-y1) * crossProd(x2-x1, y2-y1, x4-x1, y4-y1) > 0) cout << "NO"; //if P3 is on the same side of line(P1, P2) as P4
		else if (crossProd(x4-x3, y4-y3, x1-x3, y1-y3) * crossProd(x4-x3, y4-y3, x2-x3, y2-y3) > 0) cout << "NO"; //if P1 is one the same side of the line(P3, P4) as P2
		else if (crossProd(x2-x1, y2-y1, x3-x1, y3-y1) * crossProd(x2-x1, y2-y1, x4-x1, y4-y1) == 0) { // If all the four points are collinear
			if (min(x3, x4) > max(x1, x2) || max(x3, x4) < min(x1, x2) || max(y1, y2) < min(y3, y4) || min(y1, y2) > max(y3, y4)) cout << "NO"; //if the rectangles formed by diag(P1, P2) and diag(P3, P4) are disjoint
			else cout << "YES"; //the two line segments are collinear and they overlap
		}
		else cout << "YES";
		cout << '\n';
	}
	return 0;
}
