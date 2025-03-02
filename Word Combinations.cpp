#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

class Trie{
public:
Trie* children[26];
bool isEnd;
	Trie() {
		for (int i=0; i<26; i++) children[i] = NULL;
		isEnd = 0;
	}
	void addWord(string& word) {
		Trie* node = this;
		for (char& c: word) {
			if (node->children[c-'a'] == NULL) node->children[c-'a'] = new Trie();
			node = node->children[c-'a'];
		}
		node->isEnd = 1;
	}
	bool hasWord(string& word) {
		Trie* node = this;
		for (char& c: word) {
			if (node->children[c-'a'] ==  NULL) return 0;
			node = node->children[c-'a'];
		}
		if (node->isEnd) return 1;
		return 0;
	}
};

ll solve(Trie* myTrie, string& str) {
	vector<ll> dp(str.length());
	dp.push_back(1);
	for (int i=str.length()-1; i>=0; i--) {
		Trie* itr = myTrie;
		for (int j=i; j<str.length(); j++) {
			if (itr->children[str[j]-'a'] == NULL) break;
			itr = itr->children[str[j]-'a'];
			if (itr-> isEnd) dp[i] = (dp[i] + dp[j+1]) % MOD;
		}
	}
	return dp[0];
}

int main() {
	string str; cin>>str;
	int k; cin>>k;
	Trie* myTrie = new Trie();
	for (int i=0; i<k; i++) {
		string word; cin>>word;
		myTrie->addWord(word);
	}
	cout << solve(myTrie, str);
	return 0;
}

