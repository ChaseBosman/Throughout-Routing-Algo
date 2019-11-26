#include <iostream>
#include "nodes.cpp"
#include "node_structs.h"
#include "routing.cpp"
#include <vector>

using namespace std;
 


int main()
{
	int NODES = 8;
	struct Graph *G = CreateGraph(NODES);
	//define 
	// insert nodes
	//InsertNode(Graph, node1, node2, weight)

	InsertNode(G, 1, 2, 6);
	InsertNode(G, 1, 7, 2);
	InsertNode(G, 1, 3, 4);
	InsertNode(G, 2, 7, 3);
	InsertNode(G, 2, 6, 7);
	InsertNode(G, 3, 7, 2);
	InsertNode(G, 3, 4, 8);
	InsertNode(G, 3, 5, 7);
	InsertNode(G, 6, 7, 1);
	InsertNode(G, 8, 6, 1);
	InsertNode(G, 8, 1, 10);
	InsertNode(G, 2, 0, 5);
	

	int distance[NODES + 1];
	vector <vector <int> > path(NODES + 1);
	path = dijkstra(G, 1, distance);

	int test = G->vl[1].vlisthead->curr_delay(1);

	if(test == 0)
	{
		//send packet
	}



	cout << "\n\n";
	cout<<"\nThe incidence list representation for the given graph: ";
	for(int i = 0; i < NODES; i++)
	{
		cout<<"\n\tV("<<i+1<<") -> {  ";
		while(G->vl[i+1].vlisthead != NULL)
		{
			cout<<G->vl[i+1].vlisthead->data<<"-"<<G->vl[i+1].vlisthead->weight << " ";
			G->vl[i+1].vlisthead = G->vl[i+1].vlisthead->link;
		}
		cout<<"}";
	}
	cout << "\n\n";
}
