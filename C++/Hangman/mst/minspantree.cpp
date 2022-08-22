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
#include <climits>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

using iPair = pair<int, int>;

class ParPtrTree {
  private:
    vector<int> parents;
    vector<int> weights;
  public:
    ParPtrTree(size_t size) {
        parents.resize(size);
        fill(parents.begin(), parents.end(), -1);
        weights.resize(size);
        fill(weights.begin(), weights.end(), 1);
    }
    int FIND(int node)
    {
        if (parents[node] == -1) return node;
        parents[node] = FIND(parents[node]);
        return parents[node];
    }
    
    void UNION(int node1, int node2) {
        int root1 = FIND(node1);
        int root2 = FIND(node2);
        if (root1 != root2) {
            if (weights[root1] < weights[root2]) {
                parents[root1] = root2;
                weights[root2] += weights[root1];
            }
            else {
                parents[root2] = root1;
                weights[root1] += weights[root2];
            }
        }
    }
    
    string toString() {
        string nodes = "nodes:\t";
        string prts = "parents:\t";
        for (int i=0; i < this->parents.size(); i++) {
            prts += to_string(this->parents[i]) + '\t';
            nodes += " \t " + to_string(i);
        }
        return prts + "\n" + nodes;
    }
};

struct Edge
{
    int src, dest, weight;
     bool operator<(const Edge &other) const {
        return this->weight > other.weight;
    }
};

struct Graph
{
    int V, E;
    priority_queue<Edge, vector<Edge> > edges;
    Graph(int v, int e) {
        V = v;
        E = e;
    }
    
    void addEdge(int u, int v, int w) {
        edges.push({u, v, w});
    }
};

int KruskalMST(Graph& graph, vector<iPair> & MST)
{
    if (graph.E == 0)
        return 0;

    int numMST = graph.V;
    ParPtrTree unionfind(graph.V);
    int weight = 0;

    while (numMST > 1 && !graph.edges.empty())
    {
        Edge edge = graph.edges.top();
        graph.edges.pop();
        int x = unionfind.FIND(edge.src);
        int y = unionfind.FIND(edge.dest);
        if (x != y)
        {
            int u = edge.src;
            int v = edge.dest;
            weight += edge.weight;
            if (u > v) swap(u, v);
            MST.push_back({u, v});
            unionfind.UNION(u, v);
            numMST--; 
        }
    }
    return weight;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    int n=0,m=0,u=0,v=0,w=0;
    while (cin>>n>>m && n)
    {
        Graph graph(n, m);
        vector<iPair> mst;
        for (int i=0;i<m;i++)
        {
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        int wt;
        wt = KruskalMST(graph, mst);
        if (mst.size() == n-1)
        {
            cout << wt << endl;
            for(auto &p:mst)
            cout << p.first <<  " " << p.second << endl;
        }
        else cout << "Impossible" << endl;
    }
    return 0;
}

