#include <iostream>

#include "Graph.h"

using std::cout;
using std::endl;

int main() {

	Graph G(5);
	G.init();
	G.addEdge(0, 1);
	G.addEdge(0, 3);
	G.addEdge(1, 4);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(4, 3);


	G.print();

	system("pause");
	return 0;
}
