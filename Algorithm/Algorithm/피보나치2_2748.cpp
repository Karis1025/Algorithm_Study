#include <iostream>
#include <vector>

using namespace std;
long long Fibo(int num, vector<long long>& memoization)
{
	if (memoization[num] != -1)
		return memoization[num];

	memoization[num] = Fibo(num - 1, memoization) + Fibo(num - 2, memoization);
	return memoization[num];
}

//int Fibo(int num)
//{
//	if (num == 0)
//		return 0;
// 
//	if (num == 1 || num == 2)
//		return 1;
//
//	return Fibo(num - 1) + Fibo(num - 2);
//}

int main()
{
	int num{};
	cin >> num;
	
	vector<long long> memoizaion(1000, -1);
	memoizaion[0] = 0;
	memoizaion[1] = 1;
	cout << Fibo(num, memoizaion);
	//cout << Fibo(num);
}