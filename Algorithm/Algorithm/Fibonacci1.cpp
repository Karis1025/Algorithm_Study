// 피보나치 수열 - 재귀함수 
// 값 6765

#include <iostream>

int Fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;

	return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	std::cout << Fibo(20);
}