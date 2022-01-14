#include <iostream>

using namespace std;

int main()
{
	int t, n, m, tmp, answer;
	
	cin >> t;
	while (t--)
	{
		answer = 0;
		cin >> n >> m;

		for (int i = n; i <= m; i++)
		{
			tmp = i;
			do
			{
				answer = tmp % 10 == 0 ? answer + 1 : answer;
				tmp /= 10;
			} while (tmp != 0);
		}

		cout << answer << '\n';
	}

	return 0;
}