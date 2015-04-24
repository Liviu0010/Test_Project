#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
    Graph<int> g;
    vector<int> v;

    for(int i=1; i<=6; i++)
        g.addInfo(i,i);

    g.addEdge(1, 2);
    g.addEdge(1,5);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(5,4);
    g.addEdge(4,3);

    v = g.BFS(1);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';

    return 0;
}
