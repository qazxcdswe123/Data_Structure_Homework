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

    void print() const;
};


#endif //GRAPH_H
