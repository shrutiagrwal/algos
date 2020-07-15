#include <bits/stdc++.h>
using namespace std;
vector<int> kahn(vector<vector<int>> &adjlist,int n,vector<int>degree)
{
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=n;i++)
	{
		if(degree[i]==0)
		q.push(i);
	}
	vector<int>res;
	int count=0;
	while(!q.empty())
	{
		int curr=q.front();
		res.push_back(curr);
		count++;
		q.pop();
		for(int u:adjlist[curr])
		{
			degree[u]--;
			if(degree[u]==0)
			q.push(u);
		}
	}
	return res;
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adjlist(n+1);
	vector<int>degree(n+1,0);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adjlist[x].push_back(y);
		degree[y]++;
	}
 	vector<int> res=kahn(adjlist,n,degree);
 	if(res.size()==n)
 	{
 		for(int i=0;i<res.size();i++)
 		cout<<res[i]<<" ";
 	}
 	else cout<<"Sandro fails.";
}
