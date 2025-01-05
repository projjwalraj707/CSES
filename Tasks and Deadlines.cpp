#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	 int n; cin>>n;
	 ll sum = 0;
	 vector<int> arr(n);
	 for (int i=0, temp; i<n; i++) {
		 cin>>arr[i];
		 cin>>temp;
		 sum += temp;
	 }
	 sort(arr.begin(), arr.end());
	 ll prefSum = 0;
	 for (int& x: arr) {
		 prefSum += x;
		 sum -= prefSum;
	 }
	 cout << sum;
	return 0;
}
