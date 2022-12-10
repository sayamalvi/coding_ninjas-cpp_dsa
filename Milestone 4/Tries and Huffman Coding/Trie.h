#include <bits/stdc++.h>
#include "TrieNode.h"
using namespace std;
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return search(root->children[index], word.substr(1));
        }
        else
            return false;
    }
    bool search(string word)
    {
        if (word.size() == 0)
            return false;
        return search(root, word);
    }
    void remove(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
        }

        TrieNode *child;
        if (root->children[word[0] - 'a'] != NULL)
        {
            child = root->children[word[0] - 'a'];
        }
        else
            return;
        remove(child, word.substr(1));

        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[word[0] = 'a'] = NULL;
        }
    }
    void remove(string word)
    {
        remove(root, word);
    }
};