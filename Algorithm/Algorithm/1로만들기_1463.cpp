// 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

// X가 3으로 나누어 떨어지면, 3으로 나눈다.
// X가 2로 나누어 떨어지면, 2로 나눈다.
// 1을 뺀다.
// 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.연산을 사용하는 횟수의 최솟값을 출력하시오.

using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

//priority_queue<int, vector<int>, greater<int>> pq;

void Func(int num, int cnt, vector<int>& memoization)
{
	if (cnt >= memoization[num]) return;
	memoization[num] = cnt;

	if (num == 1)
	{
		//pq.push(cnt);
		return;
	}

	if (num % 3 == 0)
	{
		Func(num / 3, cnt+1, memoization);
	}
	
	if (num % 2 == 0)
	{
		Func(num / 2, cnt+1, memoization);
	}

	Func(num - 1, cnt+1, memoization);
}

int main()
{
	int num{};
	cin >> num;
	vector<int> memoization(num + 1, numeric_limits<int>::max());

	Func(num, 0, memoization);
	//cout << pq.top();
	cout << memoization[1];
}