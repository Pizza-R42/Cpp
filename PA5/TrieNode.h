
#include <unordered_map>

#ifndef TrieNode_h
#define TrieNode_h

class TrieNode {
    
public:
    
    unordered_map<char, TrieNode*> edges;
    int depth;
    
    TrieNode(int depth) {
        this->depth = depth;
    }
};

#endif /* TrieNode_h */
