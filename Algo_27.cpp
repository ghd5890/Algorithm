#include <iostream>

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
	int answer = 0;

	for (int i = 1; i < n; i++)
	{
		if (n % i == 1)
		{
			answer = i;
			break;
		}
	}

	return answer;
}