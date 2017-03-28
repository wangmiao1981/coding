class TrieNode {
public:    
  TrieNode *child[26];
  bool isWord;
  TrieNode() : isWord(false) {
      for (auto& a : child) {
          a = NULL;
      }
  }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->child[idx] == NULL) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchUtil(word, root);
    }
private:
    bool searchUtil(string word, TrieNode * node) {
        if(word.size() == 0) return node->isWord; // this line is for the case we hit the end of the word from recursive call
        TrieNode *p = node;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                // if it is '.', try all branches
                for (int j = 0; j < 26; j++) {
                    if (p->child[j] && searchUtil(word.substr(i+1), p->child[j])) {
                        // if any branch returns true, we return true;
                        return true;
                    }
                }
                // there is no branch returns true
                return false;
            } else {
                int idx = word[i] - 'a';
                if (!p->child[idx]) return false;
                p = p->child[idx];
            }
        }
        // for the case, there is no '.'
        return p->isWord;
    }
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
