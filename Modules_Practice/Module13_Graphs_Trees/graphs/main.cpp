#include "include/Graph.hpp"
int main()
{
    Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(1,4,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
  
    g.depth(0);
    g.width(0);

    std::cout << g.findPathCount(0, 3) << std::endl;
    return 0;
}