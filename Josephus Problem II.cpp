// couldn't solve it correctly
// Here is the easiest solution I found that uses set: https://github.com/mrsac7/CSES-Solutions/blob/master/src/2163%20-%20Josephus%20Problem%20II.cpp
// I just got to know that this problem can be solved using Policy Basaed Data Structure: https://youtu.be/KnsDFCcBJbY?si=bXSjW9U8V5w4bhzV
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int josephus(int n, int k) {
    return n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
}

int main() {
	int n, k; cin>>n>>k;
	for (int i=1; i<=n; i++) cout << josephus(i, n, k) << ' ';
	return 0;
}

