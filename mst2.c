#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 9999999

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int i,j;
void initializeGraph() {
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = INF;
        }
    }
}

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; // Since the graph is undirected
}

int getMinKey(int key[], bool mstSet[]) {
    int min = INF;
    int minIndex = -1;
	int v;
    for (v = 0; v < numVertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[]) {
    printf("Edge \tWeight\n");
    for ( i = 1; i < numVertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST() {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
	int count,v;
    for ( i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < numVertices - 1; count++) {
        int u = getMinKey(key, mstSet);
        mstSet[u] = true;

        for (v = 0; v < numVertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main() {
    int numEdges, u, v, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    initializeGraph();

    for (i = 0; i < numEdges; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
    }

    printf("Minimum Spanning Tree using Prim's algorithm:\n");
    primMST();

    return 0;
}

