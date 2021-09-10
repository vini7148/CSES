#include "quicksort.h"
#include "heapsort.h"
#include "selectionsort.h"
#include "binarysearch.h"
#include "graph.h"

int main()
{
    std::cout << "TESTING QUICKSORT........" << std::endl;
    test_quicksort();

    std::cout << "TESTING HEAPSORT........" << std::endl;
    test_heapsort();

    std::cout << "TESTING SELECTIONSORT........" << std::endl;
    test_selectionsort();

    std::cout << "TESTING BINARY SEARCH........" << std::endl;
    test_binary();

    graph G;
    G.rand_input();
    std::cout << "THE GRAPH IS......" << std::endl;
    G.print_graph();
    std::cout << "THE BFS IS........" << std::endl;
    G.bfs(2);
    std::cout << "THE DFS IS........" << std::endl;
    G.dfs(2);
    std::cout << "THE DIJ IS........" << std::endl;
    std::cout << G.dij(2, 13) << std::endl;

    return 0;
}