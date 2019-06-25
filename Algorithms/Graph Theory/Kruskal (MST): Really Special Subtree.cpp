#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class UnionFind {
    private: 
        vector<int> p, rank;
    public:
        UnionFind(int N)
        {
            rank.assign(N+3, 0);
            p.assign(N+3, 0);
            for (int i = 1; i <= N; i++)
                p[i] = i;
        }
        int findSet(int i)
        {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j)
        {
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y])
                    p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) 
                        rank[y]++; 
                }
            } 
        } 
};


int main()
{
    int N,E;
    cin >> N >> E;
    UnionFind graph = UnionFind(N);
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<E;i++)
    {
        int node1,node2,weight;
        cin >> node1 >> node2 >> weight;
        edges.push_back(make_tuple(weight,node1,node2));
    }
    sort(edges.begin(),edges.end());
    vector<tuple<int,int,int>>::iterator it;
    int ans = 0;
    for(it = edges.begin();it!=edges.end();++it)
    {
        if(graph.findSet(get<1>(*it)) != graph.findSet(get<2>(*it)))
        {
            graph.unionSet(get<1>(*it),get<2>(*it));
            ans += get<0>(*it);
        }
    }
    cout << ans << endl;
    return 0;
}
