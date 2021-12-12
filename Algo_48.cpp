#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MAX 1000

using namespace std;

int solution(int left, int right);

int main()
{
	int left, right;

	cin >> left >> right;
	cout << solution(left, right) << '\n';

	return 0;
}

int solution(int left, int right)
{
	int answer = 0;
	bool isPrime[MAX + 1] = { false };

	for (int i = 0; i <= MAX; i++) isPrime[i] = true;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= MAX; j += i) isPrime[j] = false;
		}
	}

	for (int i = left; i <= right; i++)
	{
		int result = 1; int cur_num = i;
		for (int div = 2; div <= i; div++)
		{
			if (isPrime[div])
			{
				int cnt = 0;
				while (cur_num % div == 0)
				{
					cnt++;
					cur_num /= div;
				}
				result *= (cnt + 1);
			}
		}

		answer = result % 2 == 0 ? answer + i : answer - i;
	}

	return answer;
}