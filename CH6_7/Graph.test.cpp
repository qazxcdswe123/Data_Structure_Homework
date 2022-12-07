//
// Created by yn on 23/11/2022.
//

#include "MatrixGraph.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("MatrixGraph", "[MatrixGraph]") {
    SECTION("init") {
        MatrixGraph<int> graph(5);
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addVertex(4);

        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 2);
        graph.addEdge(0, 3, 3);
        graph.addEdge(1, 2, 4);
        graph.addEdge(1, 3, 5);
        graph.addEdge(2, 3, 6);

        graph.printBFS();
        graph.printDFS();

        graph.printShortestPathDijkstra(0, 3);
        graph.printShortestPathBellmanFord(0, 3);
        graph.printShortestPathFloydWarshall(0, 3);

        graph.printMSTPrim();
        graph.printMSTKruskal();
    }
}



