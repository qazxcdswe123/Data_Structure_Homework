//
// Created by yn on 4/12/2022.
//

#ifndef SINGLYLINKEDLIST_CPP_MATRIXGRAPH_H
#define SINGLYLINKEDLIST_CPP_MATRIXGRAPH_H

#include <vector>

// adjacency matrix graph implementation

class Edge {
public:
    int source;
    int dest;
    int weight;

    Edge(int source, int dest, int weight) {
        this->source = source;
        this->dest = dest;
        this->weight = weight;
    }
};

template<class T>
class Vertex {
public:
    T data;
    bool visited;
};

template<class T>
class MatrixGraph {
private:
    std::vector<Vertex<T>> vertices;
    std::vector<std::vector<int>> adjMatrix;
    int numVertices;
    int numEdges;

public:
    explicit MatrixGraph(int numVertices);
    ~MatrixGraph() = default;
    void addEdge(int source, int dest, int weight);
    void addVertex(T data);

    // Graph Algorithms
    // Traversal
    void printBFS();
    void printDFS();

    // Shortest Path
    void printShortestPathDijkstra(int source, int dest);
    void printShortestPathBellmanFord(int source, int dest);
    void printShortestPathFloydWarshall(int source, int dest);

    // Minimum Spanning Tree
    void printMSTKruskal();
    void printMSTPrim();
};


#endif //SINGLYLINKEDLIST_CPP_MATRIXGRAPH_H