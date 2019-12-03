#ifndef NODESTRUCT_H
#define NODESTRUCT_H
#include <iostream>
#include <time.h>
using namespace std;



// A structure to represent a node in the adjacency list.
struct node
{
	int data;
	int weight;
	struct node *link;

	int curr_delay(int val_in)
	{
		srand(time(NULL) * val_in);

		//Delays involving actual measurements that can be analyzed
		int nodal_processing = rand() % 5;
		int queue_delay = rand() % 5;


		//buffer_open helps ensure that current buffer has available space
		//a 0 simulates no available buffer space
		bool buffer_open = rand() % 2;
		//if(!buffer_open)
			//return -1;

		int total_delay = (nodal_processing + queue_delay)/2;

		return total_delay;
		
	}
	
};
 

// A structure to represent list of vertexes connected to the given vertex.
struct nodeList
{
	struct node *listhead;
};
 

// A structure to maintain the graph vertexes and its connections to other vertexes.
struct Graph
{
	int v;
	struct nodeList *vl; 
};


#endif