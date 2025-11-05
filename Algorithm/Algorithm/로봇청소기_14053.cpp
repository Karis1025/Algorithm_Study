#include<iostream>
#include <vector>

int nextDirection(int num)
{
	return (num + 3) % 4;
}

int backDirection(int num)
{
	return (num + 2) % 4;
}

using namespace std;
int get_count_of_departments_cleaned_by_robot_vacuum(int nowR, int nowC, int d, vector<vector<int>>& room_map)
{
	// [북, 동, 남, 서]
	vector<int> r = { -1, 0, 1, 0 };
	vector<int> c = { 0, 1, 0, -1 };

	int cnt{};

	while (true)
	{
		// [현재 위치 청소]
		if (room_map[nowR][nowC] == 0)
		{
			room_map[nowR][nowC] = 2;
			cnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			// [청소해야 할 위치]
			d = nextDirection(d);
			int nextR = r[d];
			int nextC = c[d];

			// [청소 가능 하다면]
			if (room_map[nowR + nextR][nowC + nextC] == 0)
			{
				nowR = nowR + nextR;
				nowC = nowC + nextC;
				break;
			}

			// [청소가 불가능하고 뒤가 막혀있다면]
			else if (i == 3)
			{
				int backD = backDirection(d);
				nextR = r[backD];
				nextC = c[backD];

				if (room_map[nowR + nextR][nowC + nextC] == 1)
					return cnt;

				else // [뒤가 막혀있지 않다면]
				{
					nowR = nowR + nextR;
					nowC = nowC + nextC;
				}
			}
		}
	}

	return cnt;
}

void Test1()
{
	// 57 출력
	int current_r;
	int current_c;
	int current_d;
	int r;
	int c;
	cin >> r >> c;
	cin >> current_r >> current_c >> current_d;
	vector<vector<int>> graph(r, vector<int>(c));
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> graph[i][j];
		}
	}

	cout << get_count_of_departments_cleaned_by_robot_vacuum(current_r, current_c, current_d, graph);
}

void Test2()
{
	int current_r = 7;
	int current_c = 4;
	int current_d = 0;

	vector<vector<int>> graph =
	{
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
		 {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		 {1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
		 {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	cout << get_count_of_departments_cleaned_by_robot_vacuum(current_r, current_c, current_d, graph);
}
int main()
{
	Test2();
}