#include<bits/stdc++.h> 
using namespace std; 
typedef  pair<int, int> iPair; 
struct Graph 
{ 
    int V, E,count=86; 
    vector< pair<int, iPair> > edges; 
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    }
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
    int kruskalMST(); 
}; 
struct DisjointSets 
{ 
    int *parent, *rnk,count2=0; 
    int n; 
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
int Graph::kruskalMST() 
{ 
    int mst_wt = 0; 
    sort(edges.begin(), edges.end()); 
    DisjointSets ds(V); 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
    	// ++count;
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
        if (set_u != set_v) 
        { 
        	// ++count;
            cout << u << " - " << v << endl; 
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 
int main() 
{ 

    int V = 9, E = 28; 
    Graph g(V, E); 
    DisjointSets h();
    g.addEdge(0, 1, 4); 
    g.addEdge(1, 0, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(7, 0, 8);  
    g.addEdge(1, 2, 8);
    g.addEdge(2, 1, 8); 
    g.addEdge(1, 7, 11);
    g.addEdge(7, 1, 11); 
    g.addEdge(2, 3, 7);
    g.addEdge(3, 2, 7);  
    g.addEdge(2, 8, 2);
    g.addEdge(8, 2, 2); 
    g.addEdge(2, 5, 4);
    g.addEdge(5, 2, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(4, 3, 9);
    g.addEdge(3, 5, 14); 
    g.addEdge(5, 3, 14);
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 4, 10);
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 5, 2);
    g.addEdge(6, 7, 1); 
    g.addEdge(7, 6, 1);
    g.addEdge(6, 8, 6); 
    g.addEdge(8, 6, 6);
    g.addEdge(7, 8, 7);
    g.addEdge(8, 7, 7); 
  
    cout << "Kruskal, Minimum Spanning Tree edges- \n"; 
    int mst_wt = g.kruskalMST(); 
    cout<<"Number of Steps- "<<g.count<<endl;
    return 0; 
} 