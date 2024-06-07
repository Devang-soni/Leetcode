/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
*/

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    string getShortestRoot(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                break;
            }
            node = node->children[index];
            prefix += c;
            if (node->isEndOfWord) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.getShortestRoot(word);
        }

        return result;
    }
};

