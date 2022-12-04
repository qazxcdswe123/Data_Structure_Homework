//
// Created by yn on 4/12/2022.
//

#include "MatrixGraph.h"
#include "DisjointSet.h"

#include <iostream>
#include <queue>
#include <stack>

template<class T>
MatrixGraph<T>::MatrixGraph(int numVertices) {
    this->numVertices = numVertices;
    this->numEdges = 0;
    for (int i = 0; i < numVertices; i++) {
        std::vector<int> row;
        for (int j = 0; j < numVertices; j++) {
            row.push_back(INT32_MAX); // Initialize all edges to infinity
        }
        adjMatrix.push_back(row);
    }
}

template<class T>
void MatrixGraph<T>::addEdge(int source, int dest, int weight) {
    adjMatrix[source][dest] = weight;
    numEdges++;
}

template<class T>
void MatrixGraph<T>::addVertex(T data) {
    Vertex<T> vertex;
    vertex.data = data;
    vertex.visited = false;
    vertices.push_back(vertex);
}

template<class T>
void MatrixGraph<T>::printBFS() {
    std::queue<int> queue;
    vertices[0].visited = true;
    queue.push(0);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        std::cout << vertices[current].data << std::endl;
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[current][i] != INT32_MAX && !vertices[i].visited) {
                vertices[i].visited = true;
                queue.push(i);
            }
        }
    }

    // Reset visited flags
    for (int i = 0; i < numVertices; i++) {
        vertices[i].visited = false;
    }
}

template<class T>
void MatrixGraph<T>::printDFS() {
    std::stack<int> stack;
    vertices[0].visited = true;
    stack.push(0);
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        std::cout << vertices[current].data << std::endl;
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[current][i] != INT32_MAX && !vertices[i].visited) {
                vertices[i].visited = true;
                stack.push(i);
            }
        }
    }

    // Reset visited flags
    for (int i = 0; i < numVertices; i++) {
        vertices[i].visited = false;
    }
}

template<class T>
void MatrixGraph<T>::printShortestPathDijkstra(int source, int dest) {
    int distances[numVertices];
    bool visited[numVertices];
    int previous[numVertices];

    // Initialize all distances to infinity and visited to false
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT32_MAX;
        visited[i] = false;
        previous[i] = -1;
    }

    // Distance from source to source is 0
    distances[source] = 0;

    // Loop until all vertices are visited
    for (int i = 0; i < numVertices; i++) {
        // Find the vertex with the smallest distance
        int minDistance = INT32_MAX;
        int minVertex = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minVertex = j;
            }
        }

        // Mark the vertex as visited
        visited[minVertex] = true;

        // Update distances of adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && adjMatrix[minVertex][j] != INT32_MAX) {
                int newDistance = distances[minVertex] + adjMatrix[minVertex][j];
                if (newDistance < distances[j]) {
                    distances[j] = newDistance;
                    previous[j] = minVertex;
                }
            }
        }
    }

    // Print the shortest path
    std::cout << "Shortest path from " << vertices[source].data << " to " << vertices[dest].data << ": ";
    int current = dest;
    while (current != -1) {
        std::cout << vertices[current].data << " ";
        current = previous[current];
    }
    std::cout << std::endl;
}

template<class T>
void MatrixGraph<T>::printShortestPathBellmanFord(int source, int dest) {
    int distances[numVertices];
    int previous[numVertices];

    // Initialize all distances to infinity
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT32_MAX;
        previous[i] = -1;
    }

    // Distance from source to source is 0
    distances[source] = 0;

    // Loop until all vertices are visited
    for (int i = 0; i < numVertices; i++) {
        // Update distances of adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            for (int k = 0; k < numVertices; k++) {
                if (adjMatrix[j][k] != INT32_MAX) {
                    int newDistance = distances[j] + adjMatrix[j][k];
                    if (newDistance < distances[k]) {
                        distances[k] = newDistance;
                        previous[k] = j;
                    }
                }
            }
        }
    }

    // Print the shortest path
    std::cout << "Shortest path from " << vertices[source].data << " to " << vertices[dest].data << ": ";
    int current = dest;
    while (current != -1) {
        std::cout << vertices[current].data << " ";
        current = previous[current];
    }
    std::cout << std::endl;
}

template<class T>
void MatrixGraph<T>::printShortestPathFloydWarshall(int source, int dest) {
    int distances[numVertices][numVertices];
    int previous[numVertices][numVertices];

    // Initialize all distances to infinity
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            distances[i][j] = INT32_MAX;
            previous[i][j] = -1;
        }
    }

    // Distance from vertex to itself is 0
    for (int i = 0; i < numVertices; i++) {
        distances[i][i] = 0;
    }

    // Update distances of adjacent vertices
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] != INT32_MAX) {
                distances[i][j] = adjMatrix[i][j];
                previous[i][j] = i;
            }
        }
    }

    // Loop until all vertices are visited
    for (int k = 0; k < numVertices; k++) {
        // Update distances of adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                int newDistance = distances[i][k] + distances[k][j];
                if (newDistance < distances[i][j]) {
                    distances[i][j] = newDistance;
                    previous[i][j] = previous[k][j];
                }
            }
        }
    }

    // Print the shortest path
    std::cout << "Shortest path from " << vertices[source].data << " to " << vertices[dest].data << ": ";
    int current = dest;
    while (current != -1) {
        std::cout << vertices[current].data << " ";
        current = previous[source][current];
    }
    std::cout << std::endl;
}

// MST using Prim's algorithm
template<class T>
void MatrixGraph<T>::printMSTPrim() {
    int distances[numVertices];
    bool visited[numVertices];
    int previous[numVertices];

    // Initialize all distances to infinity and visited to false
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT32_MAX;
        visited[i] = false;
        previous[i] = -1;
    }

    // Distance from source to source is 0
    distances[0] = 0;

    // Loop until all vertices are visited
    for (int i = 0; i < numVertices; i++) {
        // Find the vertex with the smallest distance
        int minDistance = INT32_MAX;
        int minVertex = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minVertex = j;
            }
        }

        // Mark the vertex as visited
        visited[minVertex] = true;

        // Update distances of adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && adjMatrix[minVertex][j] != INT32_MAX) {
                int newDistance = adjMatrix[minVertex][j];
                if (newDistance < distances[j]) {
                    distances[j] = newDistance;
                    previous[j] = minVertex;
                }
            }
        }
    }

    // Print the MST
    std::cout << "MST: ";
    for (int i = 1; i < numVertices; i++) {
        std::cout << "(" << vertices[previous[i]].data << ", " << vertices[i].data << ") ";
    }
    std::cout << std::endl;
}

// MST using Kruskal's algorithm
template<class T>
void MatrixGraph<T>::printMSTKruskal() {
    // Sort the edges by weight
    std::vector<Edge> edges;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] != INT32_MAX) {
                edges.push_back(Edge(i, j, adjMatrix[i][j]));
            }
        }
    }
    std::sort(edges.begin(), edges.end());

    // Create a disjoint set
    DisjointSet set(numVertices);

    // Loop until all vertices are visited
    std::cout << "MST: ";
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].source;
        int v = edges[i].dest;

        // Check if the edge forms a cycle
        if (set.find(u) != set.find(v)) {
            std::cout << "(" << vertices[u].data << ", " << vertices[v].data << ") ";
            set.merge(u, v);
        }
    }
    std::cout << std::endl;
}