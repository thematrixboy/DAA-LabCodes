#include<bits/stdc++.h>
using namespace std;
vector<int> adjnodes[100];
bool isVisited[100];
int main()
{
    int vertices=9,edges=22;
    for(int i = 0; i < vertices; i++)
    {
        isVisited[i + 1] = false;
    }
      for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjnodes[u].push_back(v);
        adjnodes[v].push_back(u);
    }
    int start=0;
    stack<int> s;
    s.push(start);
    cout<<"DFS(all trees):| ";
    while(!s.empty())
    {
        int popped = s.top();
    if(isVisited[popped]==true)
    cout<<"";
    else{
        isVisited[popped] = true;
        cout<<popped<<" ";
        }
    s.pop();
        for(int n: adjnodes[popped])
        {
            if(!isVisited[n])
                s.push(n);
        }
    }
    cout<<"| ";

    for(int i = 0; i <vertices; i++) {
        if(!isVisited[i])
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
