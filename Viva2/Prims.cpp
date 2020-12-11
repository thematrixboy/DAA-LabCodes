#include<bits/stdc++.h>
using namespace std;
class  vertice
{
public:int v,count=0;
	list< pair<int,int> >*adj;
	 vertice(int ver)
	 {
	 	v=ver;
	 	adj = new list< pair<int,int> > [v];
	 }
	void add(int s,int d,int c)
	{
		adj[s].push_back(make_pair(d,c));
		adj[d].push_back(make_pair(s,c));
	}
	void prim(int src)
	{
		priority_queue< pair<int,int> , vector< pair<int,int> >,greater< pair<int,int> > >q;
		int key[v],parent[v],include[v];
		memset(include,0,sizeof(include));
		for(int i=0;i<v;i++)
		{
			++count;
			key[i]=INT_MAX;
			parent[i]=-1;
		}
		int mincost=0;
		q.push(make_pair(0,src));
		key[src]=0;
		int j=0;
		while(!q.empty())
		{
			++count;
			if(j==v)
				break;
			pair<int ,int> p;
			p=q.top();
			q.pop();
			include[p.second]=1;
			j++;
			mincost+=p.first;
			list< pair<int,int> >::iterator i;
			for(i=adj[p.second].begin();i!=adj[p.second].end();i++)
			{
				++count;
				int v=(*i).first;
				int c=(*i).second;
				if(include[v]==0 && key[v] > c)
				{
					++count;
					key[v]=c;
					q.push(make_pair(key[v],v));
					parent[v]=p.second;
				}
			} 
		}
		cout<<"Prim, Minimum Spanning-Tree edges: \n";
		for(int i=1;i<v;i++)
			cout<<parent[i]<<" - "<<i<<", ";
		cout<<endl;
	}

};
int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	int v=9,e=28,src=0;
	vertice g(v);
	cout<<"Enter Src,Dst,Cost- \n";
	for(int i=0;i<e;i++)
	{
		int s,d,c;
		cin>>s>>d>>c;
		g.add(s,d,c);
	}
	g.prim(src);
	cout<<"Number of Steps- "<<g.count<<endl;
}