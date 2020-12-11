#include<iostream>
#define MAX 28
using namespace std;
typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void path(int parent[], int j)
{

    if (parent[j] == - 1) 
        return; 
    
    path(parent, parent[j]); 
  
    cout<<" - "<<j;
    
}
void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];
  int parent[10];
  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }
  dis[src_graph]=0;
  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      parent[v];
      weight=e[j].wt;
    
      if(dis[u]!=999 && dis[u]+weight < dis[v])
      { 
        dis[v]=dis[u]+weight;
        parent[v]=u;
      }  
    }
  }
  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;
    
    if(dis[u]+weight < dis[v])
    {
      cout<<"\nNegative Cycle Present! \n";
      return;
    }  
  }
     for (int i = 0; i < v; i++) 
          parent[0] = -1;
  cout<<"\nVertex\t"<<"Distance\t"<<"Path ";
  for(i=0;i<nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i]<<"\t\t"<<0;
        path(parent,i);
    cout<<endl;
  }
}
int main()
{
  int nv=9,ne=28,src_graph=0;
  edge e[MAX];
  cout<<"Enter Src,Desc,Wt-"<<endl;
  for(int i=0;i<ne;i++)
  {
    cin>>e[i].src >>e[i].dest >>e[i].wt;  
  }
  bellman_ford(nv,e,src_graph,ne);
  return 0;
}