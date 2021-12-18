#include <iostream>
#define PIGS 6
using namespace std;

int main()
{
	int t, n, idx, left, right, opposite, sum, answer;
	int pigs[2][PIGS];
	
	cin >> t;
	while (t--)
	{
		idx = 0;
		answer = 1;

		cin >> n;
		for (int p = 0; p < PIGS; p++) cin >> pigs[0][p];

		while (1)
		{
			sum = 0;
			
			for (int p = 0; p < PIGS; p++) sum += pigs[idx][p];
			if (sum > n) break;
			answer++;

			idx = (idx + 1) % 2;

			for (int p = 0; p < PIGS; p++)
			{
				left = (p + 5) % PIGS;
				right = (p + 1) % PIGS;
				opposite = (p + 3) % PIGS;
				pigs[idx][p] = pigs[(idx + 1) % 2][p] + pigs[(idx + 1) % 2][left] + pigs[(idx + 1) % 2][right] + pigs[(idx + 1) % 2][opposite];
			}
		}

		cout << answer << '\n';
	}

	return 0;
}