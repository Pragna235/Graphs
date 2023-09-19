#include <stack>

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
{
	if (visited[u] == true)
	{
		// Current node is already visited. So, return.
		return;
	}

	// Current node has not be explored before. So, mark it visited.
	visited[u] = true;

	// Traverse the adjacent nodes.
	int edges = graph[u].size();

	for (int i = 0; i < edges; i++)
	{
		int v = graph[u][i];

		dfs(v, graph, visited);
	}

	return;
}

vector<vector<int>> getTranspose(int vertices, vector<vector<int>> &graph)
{
	vector<vector<int>> transposeGraph(vertices);

	//  Generate the transpose of the given graph by reversing the direction of every edge.
	for (int i = 0; i < vertices; i++)
	{
		int edges = graph[i].size();

		for (int j = 0; j < edges; j++)
		{
			int u = graph[i][j];

			transposeGraph[u].push_back(i);
		}
	}

	return transposeGraph;
}

void dfsToFindFinishTime(int u, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stk)
{
	if (visited[u] == true)
	{
		// Current node is already visited. So, return.
		return;
	}

	// Current node has not be explored before. So, mark it visited.
	visited[u] = true;

	// Traverse the adjacent nodes.
	int edges = graph[u].size();

	for (int i = 0; i < edges; i++)
	{
		int v = graph[u][i];

		dfsToFindFinishTime(v, graph, visited, stk);
	}

	// Exploration of current node is complete. So, push it in the stack.
	stk.push(u);

	return;
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Create adjacency list for the graph.
	vector<vector<int>> graph(v);

	int e = edges.size();
	for (int i = 0; i < e; i++)
	{
		int a = edges[i][0];
		int b = edges[i][1];

		graph[a].push_back(b);
	}

	// Create an empty stack to store the vertices in descending order of their finished time.
	stack<int> stk;

	// Create a visited array to keep track of the vertices visited during DFS.
	vector<bool> visited(v, false);

	// Apply DFS to determine the finish time of all the vertices.
	for (int i = 0; i < v; i++)
	{
		if (visited[i] == false)
		{
			dfsToFindFinishTime(i, graph, visited, stk);
		}
	}

	// Get the tranpose of the given graph.
	vector<vector<int>> transposeGraph = getTranspose(v, graph);

	// Mark all the vertices as unvisited.
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	// Create a variable to store the number of connected components in the graph.
	int count = 0;

	// Visit all the SCCs one by one.
	while (stk.empty() == false)
	{
		int node = stk.top();
		stk.pop();

		if (visited[node] == false)
		{
			dfs(node, transposeGraph, visited);

			// Traversed a SCC. So, increment the count by one.
			++count;
		}
	}

	return count;
}
