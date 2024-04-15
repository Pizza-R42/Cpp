#include <iostream>
#include <string>
using namespace std;

#ifndef EDGE_H_
#define EDGE_H_

class Edge {

public:

    int src, dest;

	Edge(int src, int dest) {
		this->src = src;
		this->dest = dest;
	}

	string toString() {
		return "<" + std::to_string(src) + "," + std::to_string(dest) + ">";
	}
};

#endif /* EDGE_H_ */
