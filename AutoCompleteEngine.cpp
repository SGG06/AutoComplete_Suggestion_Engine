#include <bits/stdc++.h>
using namespace std;

//ds to follow to make a trie
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

//main engine
class AutocompleteEngine {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string currentWord,vector<string>& suggestions) {

        if (node->isEndOfWord) {
            suggestions.push_back(currentWord);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char ch = 'a' + i;
                dfs(node->children[i],currentWord + ch, suggestions);
            }
        }
    };

public:
    AutocompleteEngine() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->children[index]) return {};
            curr = curr->children[index];
        }

        vector<string> suggestions;
        dfs(curr, prefix, suggestions);
        return suggestions;
    }
};

int main() {

    AutocompleteEngine engine;

    vector<string> dictionary = {
        "apple",
        "app",
        "application",
        "apply",
        "banana",
        "bat",
        "ball",
        "cat",
        "car",
        "carbon"
    };

    for (string word : dictionary){
        engine.insert(word);
    }

    string prefix;

    cout << "Enter prefix: ";
    cin >> prefix;

    vector<string> results = engine.getSuggestions(prefix);

    if (results.empty()) {
        cout << "No suggestions found.\n";
    } 
    else {
        cout << "\nSuggestions:\n";
        for (string word : results){
            cout << word << endl;
        }
    }
    return 0;
}