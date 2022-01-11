#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n, m, cur, answer = 0;
	bool check = true, used[10] = { false };

	while (cin >> n >> m)
	{	
		answer = 0;
		check = true;

		memset(used, false, sizeof(used));
		for (int i = n; i <= m; i++)
		{
			cur = i;
			while (cur != 0)
			{
				if (used[cur % 10]) // 중복되는 숫자가 나오는 경우 while 문 탈출
				{
					check = false;
					break;
				}
				used[cur % 10] = true;
				cur /= 10;
			}

			memset(used, false, sizeof(used));
			answer = check ? answer + 1 : answer;
			check = true;
		}

		cout << answer << '\n';
	}

	return 0;
}