#include <iostream>
#include <string>
#define HOTEL 18
#define ROOM 13
#define INF 2000001

using namespace std;

int main()
{
	string answer = "";
	int n, b, h, w, cost, min = INF;// n : 참가자의 수, b : 예산, h : 호텔의 수, w : 고를 수 있는 주의 개수
	int price[HOTEL] = { 0 }, capacity[HOTEL][ROOM] = { 0 };

	cin >> n >> b >> h >> w;
	for (int i = 0; i < h; i++)
	{
		cin >> price[i];
		for (int j = 0; j < w; j++)
		{
			cin >> capacity[i][j];
			if (capacity[i][j] >= n && (n * price[i]) <= b)
			{
				cost = n * price[i];
				min = cost < min ? cost : min;
			}
		}
	}

	answer = min == INF ? "stay home" : answer;

	if (answer.empty()) cout << min << '\n';
	else cout << answer << '\n';

	return 0;
}