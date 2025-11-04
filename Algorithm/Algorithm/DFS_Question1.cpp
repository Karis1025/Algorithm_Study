#include <iostream>
#include <vector>

// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 이 출력되어야 합니다
void DFS(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int curr)
{
	// 처음 방문이 아니라면
	if (visited[curr - 1])
		return;

	// 방문 도장
	visited[curr - 1] = true;
	std::cout << curr << " ";

	// 깊게 탐색한다
	for (int i = 0; i < graph[curr - 1].size(); i++)
	{
		DFS(graph, visited, graph[curr - 1][i]);
	}
}

int main()
{
	std::vector<std::vector<int>> graph =
	{
		{2, 5, 9},
		{1, 3},
		{2, 4},
		{3},
		{1, 6, 8},
		{5, 7},
		{6},
		{5},
		{1, 10},
		{9}
	};

	std::vector<bool> visited(10, false);

	DFS(graph, visited, 1);
}