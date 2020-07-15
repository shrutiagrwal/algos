#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
int root(int i)
{
	if(i==parent[i])
	return i;
	return root(parent[i]);
}
bool sortcol( vector<int>& v1, vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
}
int main()
{
	int v;
	parent.resize(v+1);//root of every vertex
	parent.push_back(0);
	for(int i=1;i<=v;i++)
		parent.push_back(i);
	sort(edges.begin(),edges.end(),sortcol);
	cout<<edges.size();
	int cost=0;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		if(root(u)!=root(v))
		{
			parent[u]=parent[v];
			cost+=edges[i][2];
		}
	}
	cout<<cost;
}
