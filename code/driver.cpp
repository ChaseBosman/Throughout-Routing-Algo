#include <iostream>
#include "nodes.cpp"
#include "node_structs.h"
#include "routing.cpp"

using namespace std;
 


int main()
{
	int NODES = 8;
	//10 edges
	//int i, v, e, wt;
 
	// // Take the input of the number of vertex and edges the graph have.
	// cout<<"Enter the number of vertexes of the graph: ";
	// cin>>v;
	// struct Graph *G = CreateGraph(v);
	// cout<<"\nEnter the number of edges of the graph: ";
	// cin>>e;
	// int edge[e][2];
 
	// // Take the input of the adjacent vertex pairs of the given graph.
	// for(i = 0; i < e; i++)
	// {
	// 	cout<<"\nEnter the vertex pair for edge "<<i+1;
	// 	cout<<"\nV(1): ";
	// 	cin>>edge[i][0];
	// 	cout<<"V(2): ";
	// 	cin>>edge[i][1];
	// 	cout<<"Weight: ";
	// 	cin>> wt;
 
	// 	InsertNode(G, edge[i][0], edge[i][1], wt);
	// }
 
	// // Print the incidence list representation of the graph.
	// cout<<"\n\nThe incidence list representation for the given graph: ";
	// for(i = 0; i < v; i++)
	// {
	// 	cout<<"\n\tV("<<i+1<<") -> {  ";
	// 	while(G->vl[i+1].vlisthead != NULL)
	// 	{
	// 		cout<<G->vl[i+1].vlisthead->data<<"-"<<G->vl[i+1].vlisthead->weight << " ";
	// 		G->vl[i+1].vlisthead = G->vl[i+1].vlisthead->link;
	// 	}
	// 	cout<<"}";
	// }



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
	InsertNode(G, 8, 8, 0);

	dijkstra(G, 1);

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
