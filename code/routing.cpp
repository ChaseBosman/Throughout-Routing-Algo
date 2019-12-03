#include <limits.h> 
#include <iostream>
#include <vector>
#include <unordered_set>
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

vector<int> reorder_sol(int index, int src, int shortest_path[], vector<int> &new_path, int arr_size)
{
	int size = arr_size;
	if(shortest_path[index] == src)
	{
		new_path.push_back(shortest_path[index]);
		return new_path;

	}
	else
	{

		new_path.push_back(shortest_path[index]);
		reorder_sol(shortest_path[index], src, shortest_path, new_path, V);
		return new_path;

	}
}
  
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
vector <vector <int> > path_finder(Graph *G, int src, int *dist, const unordered_set<int> &delays) 
{ 

	//dist arrays keep shortest and seccond shortest path distances to node n from src
    //int dist[V]; 
	//int short_path keeps track of next node to select in regards to shortest path
  	int short_path[V]; 


  	//2d vector to keep track of all chronological paths to node n
  	vector <vector <int> > path(V);

  	//sptSet keeps track of if src has a path through i 
    bool sptSet[V]; 

  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INT_MAX;
        sptSet[i] = false; 
    }
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) 
    { 
    	node *temp_head;
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
  		temp_head = G->vl[u].listhead;
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
        // Update dist value of the adjacent vertices of the picked vertex. 
        while(G->vl[u].listhead != NULL)
		{
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[ G->vl[u].listhead->data ]  &&  G->vl[ u ].listhead->weight  &&  dist[u] != INT_MAX) 
            {
            	unordered_set<int>::const_iterator search_u = delays.find (u);
            	unordered_set<int>::const_iterator search_data = delays.find (G->vl[ u ].listhead->data);


            	//check if distance is less than current
            	if(dist[u]  +  G->vl[ u].listhead->weight  <  dist[ G->vl[u].listhead->data ]
            		&& search_u == delays.end() && search_data == delays.end())
            	{
		            if(dist[(G->vl[ u ].listhead->data)] != INT_MAX)
		            {
		            	//destination's link != src so need to call function to find remaining
		           		//adds current link and current link -1 to new_path and then appends remaining path to new_path
		            	vector<int> new_path;
		           		new_path.push_back(G->vl[ u ].listhead->data);
		           		new_path.push_back(u);
		           		short_path[G->vl[ u ].listhead->data] = u;
		           		new_path = reorder_sol(u, src, short_path, new_path, V);
						path[G->vl[ u ].listhead->data].swap(new_path);

		            }
		            else
		           	{
		           		if(u != src)
		           		{
		           			//destination's link != src so need to call function to find remaining
		           			//adds current link and current link -1 to new_path and then appends remaining path to new_path
		           			vector<int> new_path;
		           			new_path.push_back(G->vl[ u ].listhead->data);
		           			new_path.push_back(u);
		           			short_path[G->vl[ u ].listhead->data] = u;
		           			new_path = reorder_sol(u, src, short_path, new_path, V);
							path[G->vl[ u ].listhead->data].swap(new_path);
		           		}
		           		else
		           		{
		           			short_path[G->vl[ u ].listhead->data] = u;
		          			path[G->vl[ u ].listhead->data].push_back(G->vl[ u ].listhead->data);
		            		path[G->vl[ u ].listhead->data].push_back(u);
		            	}
		           	}
		           	dist[ G->vl[u].listhead->data ] = dist[u] + G->vl[ u ].listhead->weight;
		    	}
            }
            G->vl[u].listhead = G->vl[u].listhead->link;
    	} 

        G->vl[u].listhead = temp_head;

  	}
    // print the constructed distance array 
    //printSolution(dist);
    return path;
 
} 
