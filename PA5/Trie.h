#include "TrieNode.h"

#ifndef Trie_h
#define Trie_h

class Trie {
    
private:
    
    TrieNode *root;
    
public:
    
    Trie() {
        root = new TrieNode(0);
    }
    
private:
    
    TrieNode *locus(string str) { // complete this method
        TrieNode *tmp = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (tmp->edges.find(c) == tmp->edges.end()) {
                return tmp;
            }
            tmp = tmp->edges[c]; 
        }
        return tmp;
    }
    
public:
    
    void insert(string str) { // complete this method
        TrieNode *parent = locus(str);
        for (int i = parent->depth; i < str.length(); i++) {
            char c = str[i];
            TrieNode* child = new TrieNode(i + 1);
            parent->edges[c] = child;
            parent = child;
        }
   
    }
    
    bool search(string str) { // complete this method
        if (str.length() == locus(str)->depth) {
            return true;
        }
        return false;
    }
    
    static set<string> intersection(vector<string> arg1, vector<string> arg2) { // complete this method
        Trie trie = Trie();
        for (string s : arg1) {
            s += "$";
            trie.insert(s);
        }
        set<string> orderedSet;
        for (string s : arg2) {
            string tmp = s + "$";
            if (trie.search(tmp)) {
                orderedSet.insert(s);
            }
            
        }
        return orderedSet;

    }
};

#endif /* Trie_h */
