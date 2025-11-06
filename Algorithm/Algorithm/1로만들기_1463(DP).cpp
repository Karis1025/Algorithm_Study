#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;

	if (n == 0 || n == 1)
	{
		cout << 0;
		return 0;
	}

	vector<int> dp(n + 1, 0); // dp[1] = 0
	
	// [BOTTOM UP 방식] : 아래에서 부터 최적의 해를 구하고 그 해가 위의 문제의 재료로 사용된다.
	// dp[1] == 0, 
	// dp[2] == dp[1] + 1 따라서 1
	// dp[3] == dp[2] + 1 OR dp[3 / 3] + 1 따라서 2, 1중에 작은 값인 1
	// dp[4] == dp[3] + 1 OR dp[4/2 == 2] + 1 따라서 2
	// dp[5] == dp[4] + 1 따라서 3
	// 이런식으로 아래에서 부터 가장 최적의 해를 구하고 상위 문제는 아래의 해를 사용하여 최적의 해를 구한다.
	for (int i = 2; i <= n; i++)
	{
		// 항상 성공하는 것은 i - 1이기 때문에 best를 일단 이렇게 설정. 
		// + 1은 "i - 1"을 한 것 때문에 카운트 하나 증가
		int best = dp[i - 1] + 1; // i가 2라고 하면 best == dp[1]의 최적 경로 + dp[2]로의 한칸 == 2

		if (i % 2 == 0)
			best = min(best, dp[i / 2] + 1);

		if (i % 3 == 0)
			best = min(best, dp[i / 3] + 1);

		dp[i] = best;
	}

	cout << dp[n];
}