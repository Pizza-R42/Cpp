#include <iostream>
#include "BinaryTreeNode.h"
#include "TreeTraversals.h"
#include "SetsAndMaps.h"
#include "GraphAlgorithms.h"
#include "Trie.h"
using namespace std;

const static string DIRECTED_GRAPH1_PATH = "directed1.txt";
const static string DIRECTED_GRAPH2_PATH = "directed2.txt";
const static string UNDIRECTED_GRAPH1_PATH = "undirected1.txt";
const static string UNDIRECTED_GRAPH2_PATH = "undirected2.txt";
const static string TOPO1_PATH = "topo1.txt";
const static string TOPO2_PATH = "topo2.txt";
const static string TOPO3_PATH = "topo3.txt";

void printArray(char* A, int len) {
    if (0 == len)
        cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < len - 1; i++) {
            cout << A[i] << ", ";
        }
        cout << A[len - 1] << "]";
    }
}

void printArray(string array[], int len) {
    if (0 == len) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < len - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[len - 1] << "]";
}

static void printVector(vector<int>& A) {
    int len = A.size();
    if (0 == len)
        cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < len - 1; i++) {
            if (A[i] == INT_MIN)
                cout << "-infty, ";
            else if (A[i] == INT_MAX)
                cout << "infty, ";
            else
                cout << A[i] << ", ";
        }
        if (A[len - 1] == INT_MIN)
            cout << "-infty]";
        else if (A[len - 1] == INT_MAX)
            cout << "infty]";
        else
            cout << A[len - 1] << "]";
    }
}

static void printVector(vector<string>& A) {
    int len = A.size();
    if (0 == len)
        cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < len - 1; i++) {
            cout << A[i] << ", ";
        }
        cout << A[len - 1] << "]";
    }
}

static void printSet(set<string>& A) {
    if (A.size() == 0) cout << "[]";
    else {
        set<string>::iterator it = A.begin();
        cout << "[" << *it;
        it++;
        for (; it != A.end(); it++)
            cout << ", " << *it;
        cout << "]";
    }
}

static BinaryTreeNode* binaryTree() {
    BinaryTreeNode* node_22 = new BinaryTreeNode(22);
    BinaryTreeNode* node_8 = new BinaryTreeNode(8);
    BinaryTreeNode* node_16 = new BinaryTreeNode(16);
    BinaryTreeNode* node_14 = new BinaryTreeNode(14);
    BinaryTreeNode* node_20 = new BinaryTreeNode(20);
    BinaryTreeNode* node_24 = new BinaryTreeNode(24);
    BinaryTreeNode* node_8_2 = new BinaryTreeNode(8);
    BinaryTreeNode* node_0 = new BinaryTreeNode(0);
    BinaryTreeNode* node_6 = new BinaryTreeNode(6);
    BinaryTreeNode* node_11 = new BinaryTreeNode(11);
    BinaryTreeNode* node_20_2 = new BinaryTreeNode(20);
    BinaryTreeNode* node_5 = new BinaryTreeNode(5);
    BinaryTreeNode* node_70 = new BinaryTreeNode(70);

    node_22->left = node_8;
    node_22->right = node_16;
    node_8->left = node_14;
    node_8->right = node_20;
    node_16->left = node_24;
    node_16->right = node_8_2;
    node_14->left = node_0;
    node_14->right = node_6;
    node_20->right = node_11;
    node_8_2->right = node_20_2;
    node_6->left = node_5;
    node_6->right = node_70;

    return node_22;
}

static void testTreeTraversal() {
    cout << "*** Test Tree Traversals ***\n" << endl;
    cout << "Pre-order Traversal: ";
    TreeTraversals::preOrder(binaryTree());
    cout << "\nIn-order Traversal: ";
    TreeTraversals::inOrder(binaryTree());
    cout << "\nPost-order Traversal: ";
    TreeTraversals::postOrder(binaryTree());
    cout << endl << endl;
}

void testIntersection(bool useTrie) {
    vector<string> arg1;
    arg1.push_back("xyz");
    arg1.push_back("abc");
    arg1.push_back("def");
    arg1.push_back("efg");
    arg1.push_back("ghi");
    arg1.push_back("xyz");
    arg1.push_back("abc");
    arg1.push_back("abc");
    arg1.push_back("ghixx");

    vector<string> arg2;
    arg2.push_back("ghi");
    arg2.push_back("abc");
    arg2.push_back("def");
    arg2.push_back("ghix");
    arg2.push_back("eff");
    arg2.push_back("xyz");
    arg2.push_back("xyw");
    arg2.push_back("abcxyz");

    cout << "\n\n* Set Intersection *" << endl;
    cout << "\nSet 1: ";
    printVector(arg1);
    cout << endl << "Set 2: ";
    printVector(arg2);
    cout << endl << endl;

    if (useTrie) {
        set<string> answer = Trie::intersection(arg1, arg2);
        cout << "Intersection is: ";
        printSet(answer);
        cout << endl;
    }
    else {
        vector<string> answer = SetsAndMaps::intersection(arg1, arg2);
        cout << "Intersection is: ";
        printVector(answer);
        cout << endl;
    }
}

static void testSetsAndMaps() {
    cout << "*** Using Set & Map ***\n" << endl;
    char str[] = { 'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a', '$' };
    int len = sizeof(str) / sizeof(char);
    cout << "Sorted order of ";
    printArray(str, len);
    SetsAndMaps::bstSort(str, len);
    cout << " is ";
    SetsAndMaps::bstSort(str, len);
    printArray(str, len);
    testIntersection(false);
}

void testBFS() {
    cout << endl;
    string filePaths[] = { DIRECTED_GRAPH1_PATH, DIRECTED_GRAPH2_PATH, UNDIRECTED_GRAPH1_PATH, UNDIRECTED_GRAPH2_PATH };
    int numFiles = 4;
    for (int i = 0; i < numFiles; i++) {
        if (i < 2)
            printf("*** Test BFS on Directed Graph %d ***\n\n", i + 1);
        else printf("*** Test BFS on Undirected Graph %d ***\n\n", i - 1);
        GraphAlgorithms bfs(filePaths[i]);
        for (int j = 0; j < bfs.adjList.size(); j++) {
            vector<int> level = bfs.bfs(j);
            cout << "Level array (from v" << j << "):   ";
            printVector(level);
            cout << endl;
        }
        cout << endl;
    }
}

void testTopologicalSorting() {
    string filePaths[] = { TOPO1_PATH, TOPO2_PATH, TOPO3_PATH };
    int numFiles = 3;
    for (int i = 0; i < numFiles; i++) {
        printf("\n*** Test Topo %d ***\n\n", i + 1);
        GraphAlgorithms mutant(filePaths[i]);
        vector<int> topoOrder = mutant.topoOrder();
        cout << "Topological order: ";
        printVector(topoOrder);
        cout << endl;
    }
}

void testTrie() {
    Trie trie;
    cout << "*** Test Trie (Spell Checker) ***" << endl << endl;
    string dictionary[] = { "abc$", "abcd$", "bce$", "abx$", "acfe$", "bfr$",
            "de$" };
    int numWordsInDict = 7;
    for (int i = 0; i < numWordsInDict; i++)
        trie.insert(dictionary[i]);

    string document[] = { "abc", "def", "abcd", "bce", "abx", "acfe", "bfr",
            "xyz", "de", "tyu", "ab" };
    int numWordsInDoc = 11;
    bool* spellCheck = new bool[numWordsInDoc];

    for (int i = 0; i < numWordsInDoc; i++) {
        string word = document[i] + "$";
        spellCheck[i] = trie.search(word);
    }

    cout << "Dictionary: ";
    printArray(dictionary, numWordsInDict);
    cout << endl;

    cout << "Document:   ";
    printArray(document, numWordsInDoc);
    cout << endl;

    cout << endl << "Incorrect spellings: ";
    for (int i = 0; i < numWordsInDoc; i++) {
        if (!spellCheck[i])
            cout << document[i] << " ";
    }
    delete[] spellCheck;
}

int main() {
    testTreeTraversal();
    testSetsAndMaps();
    testTopologicalSorting();
    testBFS();
    testTrie();
    testIntersection(true);
    return 1;
}
