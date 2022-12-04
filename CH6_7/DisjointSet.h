//
// Created by yn on 4/12/2022.
//

#ifndef SINGLYLINKEDLIST_CPP_DISJOINTSET_H
#define SINGLYLINKEDLIST_CPP_DISJOINTSET_H

#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    explicit DisjointSet(int numVertices);
    ~DisjointSet() = default;
    int find(int vertex);
    void merge(int set1, int set2);
};

#endif //SINGLYLINKEDLIST_CPP_DISJOINTSET_H
