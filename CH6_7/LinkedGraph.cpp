//
// Created by yn on 23/11/2022.
//

#include "LinkedGraph.h"

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

template<class V, class E>
Graph<V, E>::Graph(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->vertices = new Vertex<V, E>[capacity];
}

template<class V, class E>
Graph<V, E>::~Graph() {
    for (int i = 0; i < this->size; i++) {
        // delete all edges in the adjacency list
        Edge<V, E> *edge = this->vertices[i].firstEdge;
        while (edge != nullptr) {
            Edge<V, E> *temp = edge;
            edge = edge->next;
            delete temp;
        }
    }
    delete[] this->vertices;
}

template<class V, class E>
int Graph<V, E>::getVertexIndex(V vertex) const {
    for (int i = 0; i < this->size; i++) {
        if (this->vertices[i].data == vertex) {
            return i;
        }
    }
    return -1;
}

template<class V, class E>
bool Graph<V, E>::insertVertex(V vertex) {
    if (this->size == this->capacity) {
        return false;
    }
    this->vertices[this->size].data = vertex;
    this->vertices[this->size].firstEdge = nullptr;
    this->size++;
    return true;
}

template<class V, class E>
bool Graph<V, E>::insertEdge(V from, V to, E weight) {
    int fromIndex = this->getVertexIndex(from);
    int toIndex = this->getVertexIndex(to);
    if (fromIndex == -1 || toIndex == -1) { // vertex not found
        return false;
    }
    Edge<V, E> *edge = new Edge<V, E>;
    edge->vertex = to;
    edge->weight = weight;
    edge->next = this->vertices[fromIndex].firstEdge;
    this->vertices[fromIndex].firstEdge = edge;
    return true;
}

template<class V, class E>
bool Graph<V, E>::removeVertex(V vertex) {
    int index = this->getVertexIndex(vertex);
    if (index == -1) { // vertex not found
        return false;
    }
    // delete all edges in the adjacency list
    Edge<V, E> *edge = this->vertices[index].firstEdge;
    while (edge != nullptr) {
        Edge<V, E> *temp = edge;
        edge = edge->next;
        delete temp;
    }
    // move the last vertex to the index of the vertex to be removed
    this->vertices[index] = this->vertices[this->size - 1];
    this->size--;
    return true;
}

template<class V, class E>
bool Graph<V, E>::removeEdge(V from, V to) {
    int fromIndex = this->getVertexIndex(from);
    int toIndex = this->getVertexIndex(to);
    if (fromIndex == -1 || toIndex == -1) { // vertex not found
        return false;
    }
    Edge<V, E> *edge = this->vertices[fromIndex].firstEdge;
    Edge<V, E> *prev = nullptr;
    while (edge != nullptr) {
        if (edge->vertex == to) {
            if (prev == nullptr) { // the first edge is the edge to be removed
                this->vertices[fromIndex].firstEdge = edge->next;
            } else {
                prev->next = edge->next;
            }
            delete edge;
            return true;
        }
        prev = edge;
        edge = edge->next;
    }
    return false;
}

template<class V, class E>
bool Graph<V, E>::searchVertex(V vertex) const {
    return this->getVertexIndex(vertex) != -1;
}

template<class V, class E>
bool Graph<V, E>::searchEdge(V from, V to) const {
    int fromIndex = this->getVertexIndex(from);
    int toIndex = this->getVertexIndex(to);
    if (fromIndex == -1 || toIndex == -1) { // vertex not found
        return false;
    }
    Edge<V, E> *edge = this->vertices[fromIndex].firstEdge;
    while (edge != nullptr) {
        if (edge->vertex == to) {
            return true;
        }
        edge = edge->next;
    }
    return false;
}

template<class V, class E>
void Graph<V, E>::recursiveDFSPrint(V vertex, bool *visited) const {
    int index = this->getVertexIndex(vertex);
    if (index == -1) { // vertex not found
        return;
    }
    visited[index] = true;
    std::cout << vertex << " ";
    Edge<V, E> *edge = this->vertices[index].firstEdge;
    while (edge != nullptr) {
        if (!visited[this->getVertexIndex(edge->vertex)]) {
            this->recursiveDFSPrint(edge->vertex, visited);
        }
        edge = edge->next;
    }
}

template<class V, class E>
void Graph<V, E>::iterativeDFSPrint(V vertex) const {
    int index = this->getVertexIndex(vertex);
    if (index == -1) { // vertex not found
        return;
    }
    bool *visited = new bool[this->size];
    for (int i = 0; i < this->size; i++) {
        visited[i] = false;
    }
    std::stack<V> stack;
    stack.push(vertex);
    while (!stack.empty()) {
        V v = stack.top();
        stack.pop();
        index = this->getVertexIndex(v);
        if (!visited[index]) {
            visited[index] = true;
            std::cout << v << " ";
            Edge<V, E> *edge = this->vertices[index].firstEdge;
            while (edge != nullptr) {
                if (!visited[this->getVertexIndex(edge->vertex)]) {
                    stack.push(edge->vertex);
                }
                edge = edge->next;
            }
        }
    }
    delete[] visited;
}

template<class V, class E>
void Graph<V, E>::BFSPrint(V vertex) const {
    int index = this->getVertexIndex(vertex);
    if (index == -1) { // vertex not found
        return;
    }
    bool *visited = new bool[this->size];
    for (int i = 0; i < this->size; i++) {
        visited[i] = false;
    }
    std::queue<V> queue;
    queue.push(vertex);
    while (!queue.empty()) {
        V v = queue.front();
        queue.pop();
        index = this->getVertexIndex(v);
        if (!visited[index]) {
            visited[index] = true;
            std::cout << v << " ";
            Edge<V, E> *edge = this->vertices[index].firstEdge;
            while (edge != nullptr) {
                if (!visited[this->getVertexIndex(edge->vertex)]) {
                    queue.push(edge->vertex);
                }
                edge = edge->next;
            }
        }
    }
    delete[] visited;
}

template<class V, class E>
bool Graph<V, E>::relax(V from, V to, E weight) {
    int fromIndex = this->getVertexIndex(from);
    int toIndex = this->getVertexIndex(to);
    if (fromIndex == -1 || toIndex == -1) { // vertex not found
        return false;
    }
    if (this->vertices[fromIndex].distance + weight < this->vertices[toIndex].distance) {
        this->vertices[toIndex].distance = this->vertices[fromIndex].distance + weight;
        this->vertices[toIndex].predecessor = from;
        return true; // safe to relax
    }
    return false;
}