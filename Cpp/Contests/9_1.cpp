#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};


struct AdjList
{


struct AdjListNode *head;
};


struct Graph
{
	int V;
	struct AdjList* array;
};


struct AdjListNode* newAdjListNode(
				int dest, int weight)
{
	struct AdjListNode* newNode =
			(struct AdjListNode*)
	malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}


struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)
			malloc(sizeof(struct Graph));
	graph->V = V;

	
	graph->array = (struct AdjList*)
	malloc(V * sizeof(struct AdjList));

	
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}


void addEdge(struct Graph* graph, int src,
				int dest, int weight)
{
	
	struct AdjListNode* newNode =
			newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}


struct MinHeapNode
{
	int v;
	int dist;
};


struct MinHeap
{
	int size;
	int capacity;
	int *pos;
	struct MinHeapNode **array;
};


struct MinHeapNode* newMinHeapNode(int v,
								int dist)
{
	struct MinHeapNode* minHeapNode =
		(struct MinHeapNode*)
	malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}


struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap =
		(struct MinHeap*)
	malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(
			capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array =
		(struct MinHeapNode**)
				malloc(capacity *
	sizeof(struct MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap,
								int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->dist <
		minHeap->array[smallest]->dist )
	smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->dist <
		minHeap->array[smallest]->dist )
	smallest = right;

	if (smallest != idx)
	{
	
		MinHeapNode *smallestNode =
			minHeap->array[smallest];
		MinHeapNode *idxNode =
				minHeap->array[idx];

	
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;


		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap*
								minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	
	struct MinHeapNode* root =
				minHeap->array[0];

	
	struct MinHeapNode* lastNode =
		minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	
	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = 0;

	
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}


void decreaseKey(struct MinHeap* minHeap,
						int v, int dist)
{
	
	int i = minHeap->pos[v];

	
	minHeap->array[i]->dist = dist;

	while (i && minHeap->array[i]->dist <
		minHeap->array[(i - 1) / 2]->dist)
	{
		
		minHeap->pos[minHeap->array[i]->v] =
									(i-1)/2;
		minHeap->pos[minHeap->array[
							(i-1)/2]->v] = i;
		swapMinHeapNode(&minHeap->array[i],
				&minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
if (minHeap->pos[v] < minHeap->size)
	return true;
return false;
}

int sum = 0;
int r = 0;
int s = 0;
int B[100];

void printArr(int dist[], int n)
{
  if(s <n)
    int sum = 0;
	for (int i = 0; i < n; ++i){
    if(dist[i]<1000){
            sum = sum + dist[i];}
            if(dist[i]==0){
                r=i;
            }
}
    B[r] = sum;
}
void final(int arr[]){
int m = 10000;
 for(int i = 0;i<100;i++){
 if(arr[i]!= 0){
    if(arr[i] <= m){
        m = arr[i];}
    }
 }

    int index = find(arr,arr+100,m)-arr;
    cout << "Optimal Starting Point: "<<index << "\n";
    cout << "Optimal Time to touch all vertices: "<<m << "\n";
}


void dijkstra(struct Graph* graph, int src)
{

	// Get the number of vertices in graph
	int V = graph->V;

	// dist values used to pick
	// minimum weight edge in cut
	int dist[V];

	// minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v,
									dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex
	// as 0 so that it is extracted first
	minHeap->array[src] =
		newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	while (!isEmpty(minHeap))
	{
		// Extract the vertex with
		// minimum distance value
		struct MinHeapNode* minHeapNode =
					extractMin(minHeap);

		// Store the extracted vertex number
		int u = minHeapNode->v;

		struct AdjListNode* pCrawl =
					graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			if (isInMinHeap(minHeap, v) &&
					dist[u] != INT_MAX &&
			pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				// update distance
				// value in min heap also
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	// print the calculated shortest distances
	printArr(dist, V);
}

void dfs_helper(int u, vector<vector<int> >& adj,
				bool visited[])
{
	if (visited[u])
		return;

	visited[u] = true;

	for (auto v : adj[u]) {
		if (!visited[v])
			dfs_helper(v, adj, visited);
	}
}


void getTransposeGraph(vector<vector<int> >& adj,
					vector<vector<int> >& trans_adj)
{
	for (int u = 0; u < adj.size(); u++) {
		for (auto v : adj[u]) {
			trans_adj[v].push_back(u);
		}
	}
}

void initialize_visited(bool visited[], int n)
{
	for (int u = 0; u < n; u++)
		visited[u] = false;
}


vector<int> findAllMotherVertices(vector<vector<int> >& adj)
{
	int n = adj.size();
	bool visited[n];

	// Find any mother vertex
	// in given graph, G
	initialize_visited(visited, n);
	int last_dfs_called_on = -1;

	for (int u = 0; u < n; u++) {
		if (!visited[u]) {
			dfs_helper(u, adj, visited);
			last_dfs_called_on = u;
		}
	}

	
	initialize_visited(visited, n);
	dfs_helper(last_dfs_called_on, adj, visited);

	for (int u = 0; u < n; u++) {

		// Check of the mother vertex
		// exist else return -1
		if (!visited[u]) {
			vector<int> emptyVector;
			emptyVector.push_back(-1);

			return emptyVector;
		}
	}

	int motherVertex = last_dfs_called_on;

	// trans_adj is the transpose
	// of the given Graph
	vector<vector<int> > trans_adj(n);

	// Function call to get
	// the transpose graph
	getTransposeGraph(adj, trans_adj);

	
	initialize_visited(visited, n);
	dfs_helper(motherVertex, trans_adj, visited);

	vector<int> ans;

	for (int u = 0; u < n; u++) {
		if (visited[u])
			ans.push_back(u);
	}
	// Return the required list
	return ans;
}

// Driver Code
int main()
{
int V;
	int E;
	cout << "Enter the number of vertices :";
	cin >> V;
	vector<vector<int> > adj(V);
	struct Graph* graph = createGraph(V);
	cout << "Enter the number of edges : ";
	cin >> E;
	int a,b,c;
	for(int i = 0;i<E;i++){
    cin >> a >> b >> c;
	adj[a-1].push_back(b-1);
    addEdge(graph, a, b, c);
	}



	vector<int> motherVertices = findAllMotherVertices(adj);


	if (motherVertices[0] == -1)
		cout << "No potential starting point";
	else {
		cout << "All potential starting points of the graph are : ";
		for (int v : motherVertices){
			cout << v+1 << " ";
	       dijkstra(graph, v+1);

		}
		cout << "\n";
		final(B);
	}

	return 0;
}