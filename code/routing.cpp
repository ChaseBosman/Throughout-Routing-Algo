#include <limits.h> 
#include <iostream>
#include "node_structs.h"


using namespace std;
//#include <stdio.h> 
  
// Number of vertices in the graph 
#define V 9
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++)
    {        
    	if (sptSet[v] == false && dist[v] <= min)
        {
        	min = dist[v];
        	min_index = v; 
        } 
    } 

  
    return min_index; 
} 
  
// A utility function to print the constructed distance array 
int printSolution(int dist[]) 
{ 
    cout << "Vertex \t\t Distance from Source\n"; 
    for (int i = 0; i < V; i++) 
        cout << i << " \t\t" << dist[i] << "\n"; 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(Graph *G, int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) 
    { 
    	node *temp_head;
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
  		temp_head = G->vl[u].vlisthead;
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        while(G->vl[u].vlisthead != NULL)
		{
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[ G->vl[u].vlisthead->data ]  &&  G->vl[ u ].vlisthead->weight  &&  dist[u] != INT_MAX 
                &&  dist[u]  +  G->vl[ u].vlisthead->weight  <  dist[ G->vl[u].vlisthead->data ] ) 
            {
                dist[ G->vl[u].vlisthead->data ] = dist[u] + G->vl[ u ].vlisthead->weight; 
            }
            G->vl[u].vlisthead = G->vl[u].vlisthead->link;
    	} 

        G->vl[u].vlisthead = temp_head;

  	}
    // print the constructed distance array 
    printSolution(dist); 
} 
