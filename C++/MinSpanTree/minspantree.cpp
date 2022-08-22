/*
Kattis - MinSpanTree
By: Bailey Williams
12/5/19
Program taking in a graph and finds the minimum spanning tree and
 outputs the cost, and the edges. program will output 'impossible'
 is no minimum spanning tree.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

struct edge
{
    int u,v,w;
    edge (int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (edge e) const
    {
        return w > e.w;
    }
};

void kruskal(int n, int u, int v, int w, vector<edge> g[], vector<edge> &mst, int &sum)
{
    priority_queue<edge> q;
    bool marked[n];
    memset(marked,false,sizeof(marked));
    marked[0] = true;
    for (int i=0;i<g[0].size();i++)
    {
        q.push(g[0][i]);
    }
    while (mst.size() < n-1 && !q.empty())
    {
        edge e = q.top(); q.pop();
        u = e.u;
        v = e.v;
        w = e.w;
        if (marked[u] && marked[v])
        {
            continue;
        }
        if (marked[u])
        {
            for (int i=0;i<g[v].size();i++) q.push(g[v][i]);
        }
        if (marked[v]){
            for (int i=0;i<g[u].size();i++) q.push(g[u][i]);
        }
        marked[u] = marked[v] = true;
        mst.push_back(e);
        sum += w;
    }
}

void test()
{
    int n=0,m=0,u=0,v=0,w=0, sum=0;
    vector<edge> graph[n];
    vector<edge> mst;
    n = 2;
    m = 1;
    u = 0;
    v = 1;
    w = 1;
    graph[u].push_back(edge(u,v,w));
    graph[v].push_back(edge(v,u,w));
    kruskal(n, u, v, w, graph, mst, sum);
    pair<int,int> a[n-1];
    for (int i=0;i<n-1;i++)
    {
        a[i].first = min(mst[i].u,mst[i].v);
        a[i].second = max(mst[i].u,mst[i].v);
    }
    sort(a,a+(n-1));
    assert(a[0].first == 0);
    assert(a[0].second == 1);
    assert(a[1].second == 1);
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else
    {
        test();
        int n=0,m=0,u=0,v=0,w=0;
        while (cin>>n>>m && n)
        {
            vector<edge> g[n]; //graph
            for (int i=0;i<m;i++)
            {
                cin >> u >> v >> w;
                g[u].push_back(edge(u,v,w));
                g[v].push_back(edge(v,u,w));
            }
            //MST
            vector<edge> mst;
            int sum = 0;
            kruskal(n, u, v, w, g, mst, sum);
            if (mst.size() == n-1)
            {
                    cout << sum << endl;
                    pair<int,int> a[n-1];
                    for (int i=0;i<n-1;i++)
                    {
                        a[i].first = min(mst[i].u,mst[i].v);
                        a[i].second = max(mst[i].u,mst[i].v);
                    }
                    sort(a,a+(n-1));
                    for (int i=0;i<n-1;i++)
                    {
                        cout << a[i].first << " " << a[i].second << endl;
                    }
            }
            else cout << "Impossible" << endl;
        }
    }
    return 0;
}
