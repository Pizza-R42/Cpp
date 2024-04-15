#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;

#ifndef GRAPHALGORITHMS_H_
#define GRAPHALGORITHMS_H_

class GraphAlgorithms : public Graph {
    
public:
    
    GraphAlgorithms(string &filePath) {
        readUnweightedGraph(filePath);
    }
    
    ~GraphAlgorithms() {
    }
    vector<int> t;
    vector<int> topoOrder() { // complete this method
        
        int n = adjList.size();
        vector<int> order;
        queue<int> vertexQ;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (Edge e : adjList[i]) {
                int w = e.dest;
                indegree[w]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                vertexQ.push(i); 
            }
        }
        while (vertexQ.size() > 0) {
            int v = vertexQ.front();
            vertexQ.pop();
            order.push_back(v);
            for (Edge e : adjList[v]) {
                int w = e.dest;
                indegree[w]--;
                if (indegree[w] == 0) {
                    vertexQ.push(w);
                }
            }
        }
        if (order.size() != n) {
            order.clear();
        }
        return order;
    }
    
    vector<int> bfs(int s) { // complete this method
        int n = adjList.size();
        vector<int> level(n,INT_MAX);
        queue<int> vertexQ;
        vertexQ.push(s);
        level[s] = 0;
        while (vertexQ.size() > 0) {
            int v = vertexQ.front(); 
            vertexQ.pop();
            for (Edge e : adjList[v]) {
                int w = e.dest;
                if (level[w] == INT_MAX) {
                    int d = level[v];
                    level[w] = d + 1;
                    vertexQ.push(w);
                }
            }
        }
        return level;
    }
};

#endif /* GRAPHALGORITHMS_H_ */
