#include <iostream>
#include <unordered_map>
#include <string>

typedef long long lld;
typedef unsigned long long llu;
using namespace std;

struct TrieNode {
    bool leaf;
    unordered_map<char, TrieNode*> chd;

    TrieNode() : leaf(false) { }
}

TrieNode *root;

void insert(TrieNode* x, string s, int pos) {
    if (pos == s.length()) 
        x -> leaf = true;
    else {
        char cur = s[pos];
        if (x -> chd[cur] == NULL) {
            x -> chd[cur] = new TrieNode();
        }
        insert(x -> chd[cur], s, pos + 1);
    }
}

bool find(TriNode* x, string s, int pos) {
    if (pos == s.length())
        return (x -> leaf);
    if (x -> chd[s[pos]] == NULL)
        return false;
    return find(x -> chd[s[pos]], s, pos + 1);
}

int main() {
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";

    root = new TrieNode();

    insert(root, s1, 0);
    insert(root, s2, 0);
    insert(root, s3, 0);

    cout << (find(root, "1", 0) ? "true" : "false") << endl;
    // etc.
    
    return 0;
}
