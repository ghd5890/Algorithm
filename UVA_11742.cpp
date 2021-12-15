#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned int UNS_INT;

bool pick[8] = { false };
int n, m, result;

void solution(vector<int> customers, vector<vector<int>> restraints);

int main()
{
	vector<int> customers;
	vector<vector<int>> restraints;
	while (1)
	{
		result = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		restraints = vector<vector<int>>(m);
		for (int i = 0; i < m; i++)
		{
			restraints[i] = vector<int>(3);
			for (int j = 0; j < 3; j++) cin >> restraints[i][j];
		}

		solution(customers, restraints);

		cout << result << '\n';

		memset(pick, false, sizeof(pick));
	}

	return 0;
}

void solution(vector<int> customers, vector<vector<int>> restraints)
{
	if (customers.size() == n)
	{
		int p1, p2, dist, p1_pos = -1, p2_pos = -1, real_dist;
		bool isOk = true;

		for (UNS_INT i = 0; i < m; i++) // 제약 조건 확인하기
		{
			p1 = restraints[i][0]; p2 = restraints[i][1]; dist = restraints[i][2] < 0 ? restraints[i][2] * -1 : restraints[i][2];

			for (UNS_INT p = 0; p < n; p++)
			{
				p1_pos = customers[p] == p1 ? p : p1_pos;
				p2_pos = customers[p] == p2 ? p : p2_pos;
			}
			real_dist = (p1_pos - p2_pos) < 0 ? (p1_pos - p2_pos) * -1 : (p1_pos - p2_pos);

			if (real_dist < dist) isOk = false;
			if (!isOk) break;
		}

		if (isOk) result++;

		return;
	}

	for (UNS_INT i = 0; i < n; i++)
	{
		if (!pick[i])
		{
			pick[i] = true;
			customers.push_back(i);

			solution(customers, restraints);

			pick[i] = false;
			customers.pop_back();
		}
	}

	return;
}