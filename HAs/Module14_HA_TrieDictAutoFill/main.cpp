#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
const int ALPHABET_SIZE = 26;

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pNode = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pNode->children[index])
            pNode->children[index] = getNode();
 
        pNode = pNode->children[index];
    }
 
    // mark last node as leaf
    pNode->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pNode = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pNode->children[index])
            return false;
 
        pNode = pNode->children[index];
    }
 
    return (pNode->isEndOfWord);
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}
 
// Recursive function to print auto-suggestions for given
// node.
void suggestionsRec(struct TrieNode* root,
                    string currPrefix)
{
    // found a string in Trie with the given prefix
    if (root->isEndOfWord)
        cout << currPrefix << endl;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            // child node character value
            char child = 'a' + i;
            suggestionsRec(root->children[i],
                           currPrefix + child);
        }
}
 
// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode* pNode = root;
    for (char c : query) {
        int ind = CHAR_TO_INDEX(c);
 
        // no string in the Trie has this prefix
        if (!pNode->children[ind])
            return 0;
 
        pNode = pNode->children[ind];
    }
    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (isLastNode(pNode)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(pNode, query);
    return 1;
}

int main()
{
    TrieNode* root = getNode();
    insert(root, "hello");
    insert(root, "my");
    insert(root, "name");
    insert(root, "is");
    insert(root, "ilia");
    insert(root, "sevostianov");
    insert(root, "i");
    insert(root, "am");
    insert(root, "computer");
    insert(root, "vision");
    insert(root, "engineer");

    bool does_work = true;
    std::string word;
    while (does_work) {
        cout << "\x1B[33mYour word (type '/' to eqit; '.' to clean word):\033[0m" << endl;
        if (!word.empty()) cout << word;
        std::string add_word;
        cin >> add_word;
        if (add_word.find('/') != std::string::npos) {does_work = false; continue;}
        if (add_word.find('.') != std::string::npos) {word.clear();}
        word += add_word;
        cout << "\x1B[35mSuggestions:\033[0m" << endl;
        int comp = printAutoSuggestions(root, word);
        if (comp == -1) {
            cout << "\x1B[31mNo other strings found with this prefix\041" << endl;
            word.clear();
        } else if (comp == 0) {
            cout << "\x1B[31mNo string found with this prefix\041" << endl;
            word.clear();
        }
    }   
    return 0;
}