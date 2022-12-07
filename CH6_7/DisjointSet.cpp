#include "DisjointSet.h"

DisjointSet::DisjointSet(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        parent.push_back(i);
        rank.push_back(0);
    }
}

int DisjointSet::find(int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
}

void DisjointSet::merge(int set1, int set2) {
    int parent1 = find(set1);
    int parent2 = find(set2);
    if (parent1 == parent2) {
        return;
    }
    if (rank[parent1] > rank[parent2]) {
        parent[parent2] = parent1;
    } else if (rank[parent1] < rank[parent2]) {
        parent[parent1] = parent2;
    } else {
        parent[parent2] = parent1;
        rank[parent1]++;
    }
}