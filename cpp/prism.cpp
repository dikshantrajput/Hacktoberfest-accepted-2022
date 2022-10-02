// Prism algorithm in c++
// Author name - Prasad Kokane

#include<bits/stdc++.h>

using namespace std;

#define V 6

//Selects the vertex which has the least weight edge of all unselected vertices.
int selectMinVertex(vector<int> &value, vector<bool>& setMST){
	int minimum = INT_MAX;
	int vertex;
	for(int i = 0; i < V; i++){
		if(setMST[i] == false && value[i] < minimum){
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

//Print the minimum spanning tree
void printMst(int[] parent, int graph[V][V]){
	cout << "Src.\tDest.\tWeight\n";
	for(int i = 1; i < parent.length; i++){
			cout << i << "\t" << parent[i] << "\t" << graph[i][parent[i]] << "\n";
	}
}

void findMST(int graph[V][V]){
	int parent[V];
	vector<int> value(V, INT_MAX);
	vector<bool> setMST(V, false);

	parent[0] = -1;
	value[0] = 0;

        //Iterate through all the vertices of the graph
	for(int i = 0; i < V-1; i++){
                /** from all vertices connecting the currently chosen vertices, 
                * select a vertex which adds minimum edge 
                **/
		int U = selectMinVertex(value, setMST);
		setMST[U] = true;
                /** 
                * Add newly added vertex as parent of all the vertices 
                * it connects to except those that are already chosen. 
                * This would help us print the tree later.
                **/
		for(int j = 0; j < V; j++){
			if(graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j]){
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	printMst(parent, graph);
}


int main(){
        /**
        * This is the adjacency matrix representation of graph where 
        * the weight for the edge i,i is stored in ith row and jth column 
        * **/
	int graph[V][V] = {
		{0, 4, 6, 0, 0, 0},
		{4, 0, 6, 3, 4, 0},
		{6, 6, 0, 1, 8, 0},
		{0, 3, 1, 0, 2, 3},
		{0, 4, 8, 2, 0, 7},
		{0, 0, 0, 3, 7, 0},
	};
	findMST(graph);
	return 0;
}
