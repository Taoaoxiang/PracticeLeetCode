class TrieNode {
	bool end = false;
	unordered_map<char, TrieNode*> children;
public:
	TrieNode() {}
	void insert(string &word) {
		TrieNode* root = this;
		if (word.size() == 0) { return; }
		for (int i = word.size() - 1; i >= 0;--i) {
			if (root->children[word[i]] == NULL) { root->children[word[i]] = new TrieNode(); }
			root = root->children[word[i]];
		}
		root->end = true;
	}
	bool find(string &word) {
		TrieNode* root = this;
		if (word.size() == 0) { return false; }
		for (int i = word.size() - 1; i >= 0;--i) {
			root = root->children[word[i]];
			if (root == NULL) { return false; }
			if (root->end) { return true; }
		}
		return root->end;
	}
};

class StreamChecker {
public:
	TrieNode* trie = new TrieNode();
	string s = "";
	StreamChecker(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i) {
			trie->insert(words[i]);
		}
	}

	bool query(char letter) {
		s += letter;
		if (s.size() > 2000) { s.erase(0); }
		return trie->find(s);
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */