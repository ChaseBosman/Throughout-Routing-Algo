#ifndef NODESTRUCT_H
#define NODESTRUCT_H




// A structure to represent a node in the adjacency list.
struct node
{
	int data;
	int weight;
	struct node *link;
};
 

// A structure to represent list of vertexes connected to the given vertex.
struct vertexlist
{
	struct node *vlisthead;
};
 

// A structure to maintain the graph vertexes and its connections to other vertexes.
struct Graph
{
	int v;
	struct vertexlist *vl; 
};
 
#endif