//
// Created by yn on 23/11/2022.
//

#ifndef GRAPH_H
#define GRAPH_H

template<class V, class E>
struct Edge {
    V vertex;
    E weight;
    Edge<V, E> *next;
};

template<class V, class E>
struct Vertex {
    V data;
    Edge<V, E> *firstEdge;
};

// use adjacency list to represent graph
template<class V, class E>
class Graph {
private:
    int size;
    int capacity;
    Vertex<V, E> *vertices;

    // return the index of the vertex in the vertices array, -1 if not found
    int getVertexIndex(V vertex) const;

public:
    explicit Graph(int capacity);

    ~Graph();

    bool insertVertex(V vertex);

    bool insertEdge(V from, V to, E weight);

    bool removeVertex(V vertex);

    bool removeEdge(V from, V to);

    bool searchVertex(V vertex) const;

    bool searchEdge(V from, V to) const;

    void recursiveDFSPrint(V vertex, bool *visited) const;

    void iterativeDFSPrint(V vertex) const;

    void BFSPrint(V vertex) const;

    bool relax(V from, V to, E weight);

    int Dijkstra(V from, V to, int path[]) const;

    int BellmanFord(V from, V to, int path[]) const;

    int Kruskal(V from, V to, int path[]) const;

    int Prim(V from, V to, int path[]) const;

    int Floyd_Warshall(V from, V to, int path[]) const;
};


#endif //GRAPH_H
