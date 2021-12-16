#include <iostream>
#include <algorithm>
#define MUSHROOM 10
#define INF 10000

using namespace std;

int main()
{
	int mushroom[MUSHROOM] = { 0 }, subsum[MUSHROOM] = { 0 };
	int diff = 0, min_diff = INF, min_idx = 0;

	// 버섯의 점수를 입력하기
	for (int i = 0; i < MUSHROOM; i++) cin >> mushroom[i];
	
	// 부분합 구하기
	subsum[0] = mushroom[0];
	for (int i = 1; i < MUSHROOM; i++) subsum[i] = subsum[i - 1] + mushroom[i];

	for (int i = 0; i < MUSHROOM; i++)
	{
		diff = abs(subsum[i] - 100);
		min_idx = min_diff >= diff ? i : min_idx;
		min_diff = min_diff >= diff ? diff : min_diff;
	}

	cout << subsum[min_idx] << '\n';

	return 0;
}