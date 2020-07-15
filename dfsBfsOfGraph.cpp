#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	vector<vector < int>> adjList;
	int vertices;
	Graph(int N)
	{
		vertices = N;
		adjList.resize(N);
	}

	void add_edge(int x, int y)
	{
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	void BFS(int v, vector<bool> &visited)
	{
		queue<int> q;
		q.push(v);
		visited[v] = true;
		while (!q.empty())
		{
			v = q.front();
			cout << v << " ";
			for (int u = 0; u < adjList[v].size(); u++)
			{
					if (!visited[u])
				{
					visited[u] = true;
					q.push(u);
				}
			}

			q.pop();
		}
	}

	void DFS(int v, vector<bool> &visited)
	{
		stack<int> s;
		s.push(v);
		visited[v] = true;
		while (!s.empty())
		{
			cout << s.top() << " ";
			v=s.top();
			s.pop();
			for (int u: adjList[v])
			{
				if (!visited[u])
				{
					s.push(u);
					visited[u] = true;
				}
			}
		}
	}
};

int main()
{
	int N = 15;

	Graph g(N);
	g.add_edge(1, 3);
	g.add_edge(1, 2);
	g.add_edge(1, 4);
	g.add_edge(5, 2);
	g.add_edge(2, 6);
	g.add_edge(5, 9);
	g.add_edge(5, 10);
	g.add_edge(4, 7);
	g.add_edge(4, 8);
	g.add_edge(7, 11);
	g.add_edge(7, 12);

	vector<bool> visited(N, false);

	// for (int i = 0; i < N; i++)
	// {
	// 	if (visited[i] == false)
	// 	{
	// 		g.BFS(i, visited);
	// 	}
	// }

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == false)
		{
			g.DFS(i, visited);
		}
	}

	return 0;
}
