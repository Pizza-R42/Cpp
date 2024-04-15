#include <iostream>
#include <vector>
#include <list>
#include "Graph.h"
using namespace std;

static void play() {

	Graph g;
	string file = "directed1.txt";
	g.readUnweightedGraph(file);

	for (int i = 0; i < g.adjList.size(); i++) {
		vector<Edge> &row = g.adjList[i];
		cout << "Outgoing edges of vertex " << i << ": ";
		vector<Edge>::iterator it = row.begin();
		while (it != row.end()) {
			cout << (*it).toString() << " ";
			it++;
		}
		cout << endl;
	}

}

int main() {
	play();
	return 0;
}
