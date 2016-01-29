#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//class TrieNode {
//public:
//    // Initialize your data structure here.
//    vector<TrieNode*> next;
//
//    TrieNode() {
//        for (int i = 0; i < 26; i++)
//            next.push_back(NULL);
//    }
//};
//
//class Trie {
//public:
//    Trie() {
//        root = new TrieNode();
//    }
//
//    // Inserts a word into the trie.
//    void insert(string word) {
//        insert(root, word, 0);
//    }
//
//    // Returns if the word is in the trie.
//    bool search(string word) {
//        return search(root, word, 0) == 1? true: false;
//    }
//
//    // Returns if there is any word in the trie
//    // that starts with the given prefix.
//    bool startsWith(string prefix) {
//        return search(root, prefix, 0) != 0? true: false;
//    }
//
//private:
//    TrieNode* root;
//
//    TrieNode* insert(TrieNode* node, string word, int depth) {
////        cout << "depth = " << depth << endl;
//        if (!node) node = new TrieNode();
//        if (depth == word.size())
//            return NULL;
//        char ch = word[depth];
////        cout << "ch = " << ch << " ch-'a' = " << ch-'a' << endl;
//        node->next[ch-'a'] = insert(node->next[ch-'a'], word, depth+1);
//        return node;
//    }
//
//    /*three states:
//    0: not match
//    1: exactly match
//    2: match more*/
//    int search(TrieNode*node, string word, int depth) {
//        if (!node) return 0;
//        if (depth == word.size()-1) {
//            bool flag = true;
//            for (TrieNode* x: node->next) {
//                if (x) {
//                    flag = false;
//                    break;
//                }
//            }
//            return flag? 1: 2;
//        }
//        return search(node->next[word[depth]-'a'], word, depth+1);
//    }
//};


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isEnd;

    TrieNode() {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroy(root);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->next[word[i]-'a']) {
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* res = find(word);
        return res && res->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* res = find(prefix);
        return res;
    }

private:
    TrieNode* root;

    TrieNode* find(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size() && node; i++) {
            node = node->next[word[i]-'a'];
        }
        return node;
    }

};


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    Trie trie = Trie();
    trie.insert("she");
    trie.insert("sells");
    trie.insert("sea");
    trie.insert("shells");

    cout << trie.search("shell") << endl;
    cout << trie.search("shells") << endl;
    cout << trie.startsWith("shell") << endl;
    cout << trie.startsWith("shells") << endl;

    return 0;

}
