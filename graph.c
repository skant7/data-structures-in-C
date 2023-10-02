#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for a graph
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Add an edge from vertex 'src' to vertex 'dest'
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* currentNode = graph->adjacencyList[i];
        printf("Adjacency list for vertex %d: ", i);
        while (currentNode) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}
