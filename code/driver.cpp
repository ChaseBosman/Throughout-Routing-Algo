#include <iostream>
#include "nodes.cpp"
#include "node_structs.h"
#include "routing.cpp"
#include <vector>
#include <unordered_set>

using namespace std;
 
// A utility function to print the constructed distance array 
void printDistance(int dist[],int NODES) 
{ 
    cout << "Vertex \t\t Distance from Source\n"; 
    for (int i = 0; i < NODES; i++) 
        cout << i << " \t\t" << dist[i] << "\n"; 
} 

void printPaths(vector <vector <int> > path, int NODES) 
{ 
    int rows = path.size(); 

    for (int i = 0; i < NODES + 1; i++) 
    {
    	int cols = path[i].size();
    	cout << "Shortest path to " << i << ":";
    	for(int j = 0; j < cols; j++)
    	{
    		        cout << " " << path[i][j]; 
    	}
    	cout << "\n";
    }
} 


void printGraph(Graph *G, int NODES)
{
	cout<<"\nThe current network topology is: ";
	for(int i = 0; i < NODES + 1; i++)
	{
		cout<<"\n\tV("<<i<<") -> {  ";
		while(G->vl[i].listhead != NULL)
		{
			cout<<G->vl[i].listhead->data<<"-"<<G->vl[i].listhead->weight << " ";
			G->vl[i].listhead = G->vl[i].listhead->link;
		}
		cout<<"}";
	}
	cout << "\n\n";
}


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
	
	int current_source = 1;


	int distance[NODES + 1];
	vector <vector <int> > paths(NODES + 1);
	vector <vector <int> > secondary_path(NODES + 1);
	unordered_set<int> delays;

	//delays.insert(7);

	paths = path_finder(G, current_source, distance, delays);

	int row_size = paths[0].size();


	for(int curr_row = 0; curr_row < NODES; curr_row++)
	{
		int test = 0;
		if(curr_row != current_source)
		{
			cout << "Currently routing from node " << current_source << " to node " << curr_row << "\n";
			for(int curr_pos = 1; curr_pos < row_size - 1; curr_pos++)
			{
				int test_in = G->vl[current_source].listhead->curr_delay(curr_row * curr_pos * 500);

				if(test_in > 1)
				{
					delays.insert(paths[curr_row][curr_pos]);
					cout << "Node " << paths[curr_row][curr_pos] << " is facing delay!\n";
				}

				if(test_in > test)
					test = test_in;
			}

			if(test == 0)
			{
				cout << "Message n sent with no delay! \n";
			}
			else if(test == 1)
			{
				cout << "Message n sent with only 1 tick delay caused by path! \n";
			}

			int secondary_distance[NODES + 1];
			secondary_path = path_finder(G, 1, secondary_distance, delays);

			if((test == 2 || test == 3) && distance[0] == INT_MAX)
			{
				cout << "Message n sent with delay due to necessary path! \n";
			}
			else if(test == 2 || test == 3 && distance[0] != INT_MAX)
			{
				cout << "testing new route and comparing \n";
			}
			else if(test == 4 && distance[0] == INT_MAX)
			{
				cout << "Message n sent with delay due to necessary path! \n";

			}
			else if(test == 4 && distance[0] != INT_MAX)
			{
				cout << "testing new route and comparing 4 \n";

			}
			cout << "\n\n";
		}
	}

		cout << '\n';
	printDistance(distance, NODES + 1);
	cout << "\n\n";
	printPaths(paths, NODES);
	cout << "\n";
	printGraph(G, NODES);
	
}

