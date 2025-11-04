#include<iostream>
#include <vector>
#include <queue>

//[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 이 출력되어야 합니다
void BFS(std::vector<std::vector<int>>& graph, int curr)
{
	std::vector<bool> visited(10, false);
	std::queue<int> q;
	q.push(curr);

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		visited[num - 1] = true;
		std::cout << num << " ";

		for (int i = 0; i < graph[num - 1].size(); i++)
		{
			if (visited[graph[num - 1][i]] )
				continue;

			q.push(graph[num - 1][i]);
		}
	}
}

int main()
{
	std::vector<std::vector<int>> graph =
	{
		{2, 3, 4},
		{1, 5},
		{1, 6, 7},
		{1, 8},
		{2, 9},
		{3, 10},
		{3},
		{4},
		{5},
		{6}
	};

	BFS(graph, 1);
}