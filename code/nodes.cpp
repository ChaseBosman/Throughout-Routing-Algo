
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
 

// A function to declare the graph according to the number of vertex.
struct Graph* CreateGraph(int n)
{
	int i;
	struct Graph *vlist = new Graph;
	vlist->v = n;
 
	// declare a list for n vertex.
	vlist->vl = new vertexlist[n+1];
 
	// Assign the head to NULL.
	for(i = 0; i < n+1; i++)
	{
		vlist->vl[i].vlisthead = NULL;
	}
 
	return vlist;
}
 

// A function to create a new data node.
struct node* NewNode(int value, int weight)
{
	struct node *newnode = new node;
	newnode->data = value;
	newnode->weight = weight;
	newnode->link = NULL;
 
	return newnode;
}
 

// A  function to add the edge into the undirected graph.
void InsertNode(Graph *G, int v1, int v2, int weight)
{
	node *newnode1 = NewNode(v1, weight);
	node *newnode2 = NewNode(v2, weight);

	// Connection 1, v2 to v1.
	if(G->vl[v2].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v2].vlisthead = newnode1;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		newnode1->link = G->vl[v2].vlisthead;
		G->vl[v2].vlisthead = newnode1;
	}
	// Connection 2, v1 to v2.
	if(G->vl[v1].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v1].vlisthead = newnode2;
	}
	else if(v1 != v2)
	{
		// Otherwise, add the node at the beginning.
		newnode2->link = G->vl[v1].vlisthead;
		G->vl[v1].vlisthead = newnode2;
	}
}

