#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

class Graph {
private:
	int m_verticeCount;
	vector < vector < int > > m_AdjM;
public:
	Graph(int count) : m_verticeCount(count) {}
	
	//init to all 0
	void init(void) {
		for (int i = 0; i < m_verticeCount; i++) {
			vector < int > row;
			for (int j = 0; j < m_verticeCount; j++) {
				row.push_back(0);
			}
			m_AdjM.push_back(row);
		}
	}
	//add edge
	void addEdge(int start, int end, int weight = 1) {
		m_AdjM[start][end] = weight;
		m_AdjM[end][start] = weight;
	}
	//print graph
	void print(void) {
		cout << "  ";
		for (int i = 0; i < m_AdjM.size(); i++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < m_AdjM.size(); i++) {
			cout << i << " ";
		for (int j = 0; j < m_AdjM[i].size(); j++) {
			cout << m_AdjM[i][j] << " ";
		}
			cout << endl;
		}
	}

};

#endif //end Graph.h
