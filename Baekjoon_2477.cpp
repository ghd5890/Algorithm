#include <iostream>
#include <vector>
#define POINT 6
#define DIR 0
#define DIST 1

using namespace std;

enum
{
	EAST = 0,
	WEST,
	SOUTH,
	NORTH
};

int main()
{
	int info[POINT][2];
	int k, dir, dist, square = 1, sub = 1, answer = 0;
	int frequency[4] = { 0 };

	cin >> k;
	for (int i = 0; i < POINT; i++)
	{
		cin >> dir >> dist;
		dir--;
		info[i][DIR] = dir;
		info[i][DIST] = dist;
		frequency[dir]++;
	}

	for (int i = 0; i < POINT; i++)
	{
		if (frequency[info[i][DIR]] == 1) square *= info[i][DIST];
		if (info[i][DIR] == info[(i + 2) % POINT][DIR]) sub *= info[(i + 1) % POINT][DIST];
	}

	cout << (square - sub) * k << '\n';

	return 0;
}