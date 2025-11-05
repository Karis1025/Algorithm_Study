#include <iostream>
#include <vector>
#include <map>

using namespace std;
int Fibo(map<int, int>& memoizaion, int val)
{
	auto it = memoizaion.find(val);
	if (it != memoizaion.end())
		return it->second;

	memoizaion[val] = Fibo(memoizaion, val - 1) + Fibo(memoizaion, val - 2);
	return memoizaion[val];
}

int Calc(vector<int>& vipSeat, int seatCount)
{
	map<int, int> memoization = { {0, 1}, { 1,1 }, {2,2} };
	int allCount = 1;
	int prevIndex{};
	int currIndex{};

	for (int i = 0; i < vipSeat.size(); i++)
	{
		currIndex = vipSeat[i] - 1;
		int nowCount = currIndex - prevIndex;

		allCount *= Fibo(memoization, nowCount);
		prevIndex = currIndex + 1;
	}

	int nowCount = seatCount - prevIndex;
	allCount *= Fibo(memoization, nowCount);

	return allCount;
}

int main()
{
	int seatCount{};
	int vipCount{};
	vector<int> vipSeat;

	cin >> seatCount;
	cin >> vipCount;
	for (int i = 0; i < vipCount; i++)
	{
		int num{};
		cin >> num;

		vipSeat.push_back(num);
	}

	cout << Calc(vipSeat, seatCount);
}