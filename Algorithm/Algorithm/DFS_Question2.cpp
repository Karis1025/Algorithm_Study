#include <iostream>
#include <vector>
#include <stack>

// [1, 9, 10, 5, 8, 6, 7, 2, 3, 4] 이 출력되어야 합니다
void DFS(std::vector<std::vector<int>>& graph, int curr)
{
	std::vector<bool> visited(10, false);
	std::stack<int> myStack;
	myStack.push(curr);

	while (!myStack.empty())
	{
		int num = myStack.top();
		myStack.pop();

		visited[num] = true;
		std::cout << num << " ";

		for (int i = 0; i < graph[num - 1].size(); i++)
		{
			if (visited[graph[num - 1][i]]) 
				continue;

			myStack.push(graph[num - 1][i]); // 방문하지 않은 것을 모두 stack에 쌓음 
		}
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

	DFS(graph, 1);
}