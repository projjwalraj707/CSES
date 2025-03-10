/*
	Main Sources
		1. https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf
		2. https://youtu.be/O7_w001f58c?si=zPXTbLWPUISRWQdT
		3. https://youtu.be/OFKxWFew_L0?si=08TLowQRxHj5pz8S
*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
	Trie* children[26];
	Trie* failure; //points to failure/suffix link
	Trie* output; //points to output link
	bool isWord;
	vector<int> ids; //multiple words may end at this node
	Trie() {
		for (int i=0; i<26; i++) children[i] = NULL;
		output = failure = NULL;
		isWord = 0;
	}
	void addWord(string& word, int id) {
		Trie* itr = this;
		for (char ch: word) {
			if (!itr->children[ch-'a']) itr -> children[ch-'a'] = new Trie;
			itr = itr->children[ch-'a'];
		}
		itr->isWord = 1;
		itr->ids.push_back(id);
	}
};

void addLinks(Trie* root) {
	root->failure = root;
	queue<Trie*> q; //turns out using bfs is more time-efficient that dfs/recursion (see stanford pdf)
	for (int i=0; i<26; i++) if (root->children[i]) {
		q.push(root->children[i]);
		root->children[i]->failure = root;
	}
	while (q.size()) {
		Trie* s = q.front(); q.pop();
		for (int i=0; i<26; i++) if (s->children[i]) {
			Trie* s_ = s->failure;
			Trie* e = s->children[i];
			while (s_ != root && !s_->children[i]) s_ = s_->failure;
			if (s_->children[i]) e->failure = s_->children[i];
			else e->failure = root;
			//Output Link: The first failure link that is also a word
			if (e->failure->isWord) e->output = e->failure; //if your failure link is a word, then your failure link is your output
			else e->output = e->failure->output; //else the output link of your failure link is your output link
			q.push(e);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin>>str;
	int	n, k; cin>>k;
	n = str.length();
	Trie* root = new Trie;
	for (int i=0; i<k; i++) {
		string pattern; cin>>pattern;
		root -> addWord(pattern, i);
	}
	addLinks(root); //add both failure links as well as output links
	vector<bool> ans(k);
	Trie* itr = root;
	for (char ch: str) {
		while (itr != root && !itr->children[ch-'a']) itr = itr->failure;
		if (itr->children[ch-'a']) itr = itr->children[ch-'a'];
		if (itr->isWord) for (int id: itr->ids) ans[id] = 1;
		itr->isWord = 0; //remove the word as soon as it is found to improve efficiency (see pg. 271 of standford pdf)
		Trie* outputLink = itr->output;
		while (outputLink && outputLink->isWord) {
			for (int id: outputLink->ids) ans[id] = 1;
			outputLink = outputLink->output;
		}
	}
	for (int x: ans)
		if (x) cout << "YES\n";
		else cout << "NO\n";
	return 0;
}
