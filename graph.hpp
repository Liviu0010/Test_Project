#ifndef GRAPH_HPP_INCLUDED
#define GRAPH_HPP_INCLUDED

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

template<class T>
class Graph
{
    vector< vector<int> > mAdjList;
    unordered_map<int, T> mMap;

public:
    // associate node index with T data
    bool addInfo(int index, T data)
    {
        // adjust adjacency list size if given note is higher than current size
        if (index > mAdjList.size())
            mAdjList.resize(index + 1);
        // we return true if we overwrite data and false otherwise
        bool overwrite = false;

        if (mMap[index])
            overwrite = true;

        mMap[index] = data;

        return overwrite;
    }

    bool addEdge(int leftEnd, int rightEnd)
    {
        // stop and return false if no data is found for given nodes
        if (!mMap[leftEnd] || !mMap[rightEnd])
            return false;

        // create connection in adjacency list
        mAdjList[leftEnd].push_back(rightEnd);
        mAdjList[rightEnd].push_back(leftEnd);
        return true;
    }

    /* TODO - rewrite this using our queue class
    void BFS(int src)
    {
        queue<int> q;
        bool visited[mAdjList.size()];
        fill(visited, visited + mAdjList.size(), false);

        q.push(src);
        visited[src] = true;
        int x;
        while (!q.empty())
        {
            x = q.front(), q.pop();
            cout << mMap[x] << " ";
            for (int i = 0; i < mAdjList[x].size(); i++)
                if (!visited[mAdjList[x][i]])
                {
                    visited[mAdjList[x][i]] = true;
                    q.push(mAdjList[x][i]);
                }
        }
    }*/
};


#endif // GRAPH_HPP_INCLUDED
