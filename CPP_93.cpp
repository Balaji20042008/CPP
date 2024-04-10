#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode {

    public:

    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode (char character) {

        data = character;

        for (int i = 0; i < 26; i++) {

            children[i] = NULL;
        }

        childCount = 0;

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

        int index = word[0] - 'a';

        if (root->children[index] != NULL) {

            child = root->children[index];

        } else {

            child = new TrieNode(word[0]);
            root->childCount++;
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

        int index = word[0] - 'a';

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

        // base condition

        if (word.length() == 0) {

            root->isTerminal = false;
            return;
        }

        TrieNode* child;

        int index = word[0] - 'a';

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

        remove_util (root, word);
    }

    void lcp (string str, string &ans) {

        for (int i = 0; i < str.length(); i++) {

            char ch = str[i];

            if (root->childCount == 1) {

                ans.push_back(ch);

                int index = ch - 'a'; 
                root = root->children[index];

            } else {

                break;
            }

            if (root->isTerminal) {

                break;
            }
        }
    }
};

int main () {

    Trie* trie = new Trie();

    // trie->insert_word("ARMS");
    // trie->insert_word("DUCK");
    // trie->insert_word("TIME");

    // cout << "ARMS - " << trie->search_word("ARMS") << endl;

    // cout << "TIME - " << trie->search_word("TIME") << endl;
    // cout << "DOES - " << trie->search_word("DOES") << endl;

    // trie->remove_word("TIME");
    // trie->remove_word("DOES");

    // cout << "TIME - " << trie->search_word("TIME") << endl;
    // cout << "DOES - " << trie->search_word("DOES") << endl;


    vector<string> array = {"coding", "codezen", "codingninjas", "code"};

    for (int i = 0; i < array.size(); i++) {

        trie->insert_word(array[i]);
    }

    string first = array[0]; 
    string answer = "";

    trie -> lcp (first, answer);

    // for (int i = 0; i < array[0].length(); i++) {

    //     char ch = array[0][i];
    //     bool match = true;

    //     for (int j = 1; j < array.size(); j++) {

    //         if (array[j].size() < i || ch != array[j][i]) {

    //             match = false;
    //             break;
    //         }
    //     }

    //     if (match == false) {

    //         break;
            
    //     } else {

    //         answer.push_back(ch);
    //     }
    // }

    cout << "The longest common prefix is: " << answer << endl;
}