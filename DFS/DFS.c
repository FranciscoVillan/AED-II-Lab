#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    struct Node* head[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_NODES; ++i)
        graph->head[i] = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// Recursive function to perform DFS traversal
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->head[v];
    while (temp != NULL) {
        int adjNode = temp->dest;
        if (!visited[adjNode])
            DFSUtil(graph, adjNode, visited);
        temp = temp->next;
    }
}

// Function to perform DFS traversal
void DFS(struct Graph* graph, int start) {
    int visited[MAX_NODES] = {0}; // Initialize all vertices as not visited
    DFSUtil(graph, start, visited);
}

int main() {
    // Create a graph
    struct Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Depth First Traversal starting from vertex 2: \n");
    DFS(graph, 2);

    return 0;
}
