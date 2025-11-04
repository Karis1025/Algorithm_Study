// 피보나치 수열 - 재귀함수 
// 값 6765

#include <iostream>
#include <vector>

int cnt{};

int Fibo(int n, std::vector<int>& memoization)
{
	if (n == 1 || n == 2)
		return 1;

	if (memoization[n - 1])
		return memoization[n - 1];

	cnt++; // 반복 횟수 테스트

	memoization[n - 1] = Fibo(n - 1, memoization) + Fibo(n - 2, memoization);
	return memoization[n - 1];
}

int main()
{
	std::vector<int> memoization(100, 0);
	memoization[0] = 1;
	memoization[1] = 1;

	std::cout << Fibo(20, memoization) << std::endl;
	std::cout << "반복 횟수 = " << cnt;

}