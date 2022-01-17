#include <iostream>
#include <vector>
#define MAX_DIST 100
#define MIN 0
#define DIST 0
#define SPEED 1

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<vector<int>> limit, yj;
	int n, m, dist, speed, answer = MIN;

	cin >> n >> m;
	limit = vector<vector<int>>(n);
	for (UNS_INT i = 0; i < limit.size(); i++)
	{
		cin >> dist >> speed;
		limit[i].push_back(dist);
		limit[i].push_back(speed);
	}

	yj = vector<vector<int>>(m);
	for (UNS_INT i = 0; i < yj.size(); i++)
	{
		cin >> dist >> speed;
		yj[i].push_back(dist);
		yj[i].push_back(speed);
	}

	int idx1 = 0, idx2 = 0, dist1 = 0, dist2 = 0;

	while (1)
	{
		if (dist2 == MAX_DIST || dist1 == MAX_DIST) break;
		/*
			cout << "idx1 : " << idx1 << ", idx2 : " << idx2 << ", dist1 : " << dist1 << ", dist2 : " << dist2 << ", answer : " << answer << '\n';
			cout << "제한 속도 : " << limit[idx1][SPEED] << ", 윤정의 속도 : " << yj[idx2][SPEED] << '\n';
		*/
		if (dist1 + limit[idx1][DIST] < dist2 + yj[idx2][DIST])
		{
			answer = answer < yj[idx2][SPEED] - limit[idx1][SPEED] ? yj[idx2][SPEED] - limit[idx1][SPEED] : answer;
			dist1 += limit[idx1][DIST];
			dist2 += limit[idx1][DIST];
			yj[idx2][DIST] -= limit[idx1][DIST];
			idx1++;
		}
		else if(dist1 + limit[idx1][DIST] > dist2 + yj[idx2][DIST])
		{
			answer = answer < yj[idx2][SPEED] - limit[idx1][SPEED] ? yj[idx2][SPEED] - limit[idx1][SPEED] : answer;
			dist2 += yj[idx2][DIST];
			dist1 += yj[idx2][DIST];
			limit[idx1][DIST] -= yj[idx2][DIST];
			idx2++;
		}
		else
		{
			answer = answer < yj[idx2][SPEED] - limit[idx1][SPEED] ? yj[idx2][SPEED] - limit[idx1][SPEED] : answer;
			dist1 += limit[idx1][DIST];
			dist2 += yj[idx2][DIST];
			idx1++;
			idx2++;
		}
	}

	cout << answer << '\n';

	return 0;
}