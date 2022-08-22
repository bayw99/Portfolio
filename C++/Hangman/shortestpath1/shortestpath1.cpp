/*
 Kattis - Shortest Path
 By: Bailey Williams
 11/16/19
 Program takes nodes, edges, # of queries, and index of a graph and outputs the minimum distance
 from the index to a specified node.
 */

#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <climits> // sizes of integral types
#include <utility> // make_pair
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;
#define INF 20000000

struct edge
{
    int to, weight;
    edge(){}
    edge(int _to, int _weight)
    {
        to = _to;
        weight = _weight;
    }
    bool operator < (edge e) const
    {
        return weight > e.weight;
    }
};

void dijkstra(int s, vector<edge> adjlist[], vector<int> &dist)
{
    priority_queue <edge> q;
    q.push(edge(s,0));
    dist[s] = 0;
    while(!q.empty())
    {
        edge top = q.top(); q.pop();
        int u = top.to;
        for(int i=0;i<adjlist[u].size();i++){
            int v = adjlist[u][i].to;
            if(dist[u] + adjlist[u][i].weight < dist[v]){
                dist[v] = dist[u] + adjlist[u][i].weight;
                q.push(edge(v,dist[v]));
            }
        }
    }
}

void test()
{
    vector <edge> adjlist[5];
    adjlist[0].push_back(edge(1, 10));
    adjlist[0].push_back(edge(3, 20));
    adjlist[0].push_back(edge(2, 3));
    adjlist[1].push_back(edge(3, 5));
    adjlist[2].push_back(edge(1, 2));
    adjlist[2].push_back(edge(4, 15));
    adjlist[3].push_back(edge(4, 11));
    vector <int> dist = vector<int>(5+1,INF);
    dijkstra(0, adjlist, dist);
    assert(dist[1] == 5);
    assert(dist[2] == 3);
    assert(dist[3] == 10);
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else
    {
        int n,m,qq,s,u,v,w;
        edge e,f;
        while (scanf("%d%d%d%d",&n,&m,&qq,&s) && n)
        {
            vector <edge> adjlist[n];
            for (int i=0;i<m;i++)
            {
                scanf("%d%d%d",&u,&v,&w);
                adjlist[u].push_back(edge(v,w));
            }
            vector <int> dist = vector<int>(n+1,INF);
            dijkstra(s, adjlist, dist);
            for (int i=0;i<qq;i++)
            {
                scanf("%d",&u);
                if (dist[u] == INF) printf("Impossible\n");
                else printf("%d\n",dist[u]);
            }
            printf("\n");
        }
    }
    return 0;
}


