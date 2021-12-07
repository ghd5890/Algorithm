#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n);

int main()
{
	int n;

	cin >> n;
	cout << solution(n) << '\n';

	return 0;
}

int solution(int n)
{
	int answer = 0, high = n, low = n, sum = 0;

	while (high > 0 && low > 0)
	{
		if (high == low) sum = high;
		if (sum < n)
		{
			low--;
			sum += low;
		}
		else if (sum > n)
		{
			sum -= high;
			high--;
		}
		else
		{
			char tmp = ' ';
			for (int i = low; i <= high; i++)
			{
				tmp = i != high ? '+' : '=';
				cout << i << ' ' << tmp << ' ';
			}
			cout << n << '\n';

			answer++;
			low--;
			sum += low;
		}
	}

	return answer;
}