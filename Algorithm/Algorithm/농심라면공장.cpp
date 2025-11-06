#include <iostream>
#include <vector>
#include <queue>

// 1. 받는 횟수를 최소화 해야 함.
// 2. 받을 수 있는 물품은 stock >= dates임. 남아있는 재고가 다음에 받아올 날짜까지 버텨줘야 함.
// stock < dates면 공장을 가동시키지 못함 stock이 14고 dates가 16이면 이틀간 공장이 안돌아 감.
// 3. stock >= k일 때 까지 stock을 채워야 함. 그래야 공장이 계속 가동이 됨
// 즉 stock < k라면 물품을 받아온다.
// stock >= dates인 것 중에 가장 큰 것을 받는다.
// stock이 늘어날텐데 그럼 이전에 stock < dates였던 것이 stock >= dates가 될 수 있다.
// 이렇게 되면 이젠 이것도 물품을 받아올 후보중 하나가 된다.

// stock = 4, k = 30
// [4, 6, 10, 15]
// [10, 4, 6, 30]
// 처음부터 30을 가져오면 끝날 문제지만 그렇게 되면 4일 ~ 15일 까지의 11일 동안 공장을 가동시키지 못함.
// 처음엔 4일에 받아올 수 밖에 없음 => stock이 14
// 아직도 15일차의 stock30을 받아올수 없음
// stock이 14일 때 받아올 수 있는 날짜는 6, 10일인데 이 중 가장 큰 것을 받아와야 함.
// Max힙에 6, 10일차의 stock인 4, 6을 넣는다. 
// 그 중 가장 큰 6이 먼저 stock에 쌓이고 stock은 16이 된다. 
// 이제 15일차 것을 받아올 수 있게 된다.
// 만약 15일차가 아니라 17일 차였으면 stock < dates기 때문에 6일차의 stock4도 더해야 한다.
// 15일차기 때문에 15일의 stock30을 힙에 넣는다.
// 힙에는 30, 4가 존재한다.
// 그 중 가장 큰 30을 꺼낸다.

using namespace std;
int Func(int stock, vector<int> dates, vector<int> supply, int k)
{
	priority_queue<int> pq;

	int index = 0;
	int cnt = 0;
	while (stock < k)
	{
		while (index < dates.size())
		{
			// 가능한 날짜의 stock을 모두 저장
			if (stock < dates[index])
				break;

			pq.push(supply[index]);
			index++;
		}

		// 가장 큰 stock
		int maxStock = pq.top();
		pq.pop();
		stock += maxStock;
		cnt++;
	}

	return cnt;
}

int main()
{
	//cout << Func(4, {4, 10, 15}, {20, 5, 10}, 30); // 2
	//cout << Func(4, {4, 10, 15, 20}, {20, 5, 10, 5}, 40); // 4
	//cout << Func(2, {1, 10}, {10, 100}, 11); // 1
	//cout << Func(10, { 5 }, { 20 }, 10); // 0
	//cout << Func(0, { 0, 10, 15 }, { 20, 10, 15 }, 35); // 2
	//cout << Func(10, { 10, 29 }, { 20, 100 }, 30); // 2
	cout << Func(29, {29}, {100}, 30); // 1
}
