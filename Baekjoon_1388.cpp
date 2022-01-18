#include <iostream>
#include <vector>
#include <string>
#define MAX 50

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<string> floor;
	UNS_INT n, m, y, x, idx = 0, answer = 0;
	UNS_INT move_y[2] = { 1, 0 }, move_x[2] = { 0, 1 };
	bool visited[MAX][MAX] = { false };

	cin >> n >> m;
	
	floor = vector<string>(n);
	for (UNS_INT i = 0; i < n; i++) cin >> floor[i];

	for (UNS_INT row = 0; row < n; row++)
	{
		for (UNS_INT col = 0; col < m; col++)
		{
			idx = floor[row][col] == '|' ? 0 : 1;
			if (!visited[row][col])
			{
				y = row; x = col;
				answer++;

				do
				{
					visited[y][x] = true;
					y += move_y[idx]; x += move_x[idx];
				} while ((0 <= y && y < n) && (0 <= x && x < m) && floor[y][x] == floor[row][col]);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}