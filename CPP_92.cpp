#include<iostream>
#include<string>
using namespace std;

class TrieNode {

    public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode (char ch) {

        data = ch;

        for (int i = 0; i < 26; i++) {

            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie {

    public:

    TrieNode* root;

    Trie () {

        root = new TrieNode('\0');
    }

    void insert_util (TrieNode* root, string word) {

        // base condition

        if (word.length() == 0) {

            root->isTerminal = true;
            return;
        }

        TrieNode* child;

        int index = word[0] - 'A';

        if (root->children[index] != NULL) {

            child = root->children[index];

        } else {

            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion

        insert_util (child, word.substr(1));
    }

    void insert_word (string word) {

        insert_util (root, word);
    }

    bool search_util (TrieNode* root, string word) {

        // base condition

        if (word.length() == 0) {
            
            return root->isTerminal;
        }

        TrieNode* child;

        int index = word[0] - 'A';

        if (root->children[index] != NULL) {

            child = root->children[index];

        } else {

            return false;
        }

        // recursion

        return search_util (child, word.substr(1));
    }


    bool search_word (string word) {

        return search_util (root, word);
    }

    void remove_util (TrieNode* root, string word) {

        if (word.length() == 0) {

            root->isTerminal = false;
            return;
        }

        TrieNode* child;   

        int index = word[0] - 'A';

        if (root->children[index] != NULL) {

            child = root->children[index];

        } else {

            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion

        remove_util (child, word.substr(1));
    }

    void remove_word (string word) {

        return remove_util (root, word);
    }
};

int main() {

    Trie* trie = new Trie();

    trie->insert_word("ARMS");
    trie->insert_word("DUCK");
    trie->insert_word("TIME");

    // cout << "ARMS - " << trie->search_word("ARMS") << endl;

    cout << "TIME - " << trie->search_word("TIME") << endl;
    cout << "DOES - " << trie->search_word("DOES") << endl;

    trie->remove_word("TIME");
    trie->remove_word("DOES");

    cout << "TIME - " << trie->search_word("TIME") << endl;
    cout << "DOES - " << trie->search_word("DOES") << endl;

    return 0;
}