#include <iostream>

#include "Graph.h"

using std::cout;
using std::endl;

int main() {

	Graph G(8);
	G.init();
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(0, 3);
	G.addEdge(0, 4);
	G.addEdge(1, 1);
	G.addEdge(1, 5);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(2, 7);
	G.addEdge(3, 0);
	G.addEdge(3, 2);
	G.addEdge(3, 7);
	G.addEdge(4, 0);
	G.addEdge(4, 7);
	G.addEdge(5, 1);
	G.addEdge(5, 6);
	G.addEdge(6, 5);
	G.addEdge(7, 5);
	G.addEdge(7, 4);
	G.addEdge(7, 2);
	G.addEdge(7, 3);
	G.print();

	system("pause");
	return 0;
}
