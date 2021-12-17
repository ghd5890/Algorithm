#include <iostream>
#include <algorithm>
#include <stack>
#define INF 50

using namespace std;

int main()
{
	stack<pair<int, int>> stk;
	int scores[INF] = { 0 };
	int rank[INF] = { 0 };
	int over[INF] = { 0 };
	int n, score, p, ranking = 1, overlap = 0;

	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) cin >> scores[i];

	// 랭킹 계산하는 알고리즘 O(n)
	for (int i = 0; i < n; i++) 
	{
		if (stk.empty())
		{
			stk.push(pair<int, int>(i, scores[i]));
			rank[i] = ranking;
			overlap = 1;
			over[i] = overlap;
		}
		else if (stk.top().second != scores[i])
		{
			stk.pop();
			stk.push(pair<int, int>(i, scores[i]));
			ranking += overlap;
			rank[i] = ranking;
			overlap = 1;
			over[i] = overlap;
		}
		else
		{
			rank[i] = ranking;
			overlap++;
			over[i] = overlap;
		}
	}

	int idx = 0, answer = 1;

	while (idx != n)
	{
		if (scores[idx] < score) break;
		idx++;
	}

	if (idx == 0) answer = 1;
	else if (scores[idx - 1] == score) answer = rank[idx - 1] + over[idx - 1] > p ? -1 : rank[idx - 1];
	else if (scores[idx - 1] != score) answer = rank[idx - 1] + over[idx - 1] > p ? -1 : rank[idx - 1] + over[idx - 1];
	else if (idx == p) answer = -1;

	cout << answer << '\n';

	return 0;
}