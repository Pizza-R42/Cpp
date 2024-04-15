#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Edge.h"
using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {

public:

	vector<vector<Edge>> adjList;

	Graph() {
	}

	~Graph() {
	}

	void readUnweightedGraph(string &filePath) {
		ifstream fileReader(filePath, ios::in);
        int numVertices;
		fileReader >> numVertices;
		adjList.reserve(numVertices);
		for (int i = 0; i < numVertices; i++) {
			int numEdges;
			fileReader >> numEdges;
			vector<Edge> outEdges;
			for (int j = 0; j < numEdges; j++) {
				int dest;
				fileReader >> dest;
				Edge edge(i, dest);
				outEdges.push_back(edge);
			}
			adjList.push_back(outEdges);
		}
		fileReader.close();
	}
};

#endif /* GRAPH_H_ */
