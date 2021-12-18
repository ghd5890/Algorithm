#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> map;
	int r, c, cur_y, cur_x, nxt_y, nxt_x;
	int move_y[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
	int move_x[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };

	while (1)
	{
		cin >> r >> c;
		if (r == 0 && c == 0) break;
		
		// 지도를 입력
		map = vector<string>(r);
		for (int i = 0; i < r; i++) cin >> map[i];

		// 알고리즘 동작
		for (int row = 0; row < r; row++)
		{
			for (int col = 0; col < c; col++)
			{
				if (map[row][col] == '*')
				{
					cur_y = row, cur_x = col;
					for (int dir = 0; dir < 8; dir++)
					{
						nxt_y = cur_y + move_y[dir]; nxt_x = cur_x + move_x[dir];
						if (nxt_y < 0 || nxt_y >= r || nxt_x < 0 || nxt_x >= c) continue;

						if (map[nxt_y][nxt_x] == '.') map[nxt_y][nxt_x] = '1';
						else if (map[nxt_y][nxt_x] >= '1' && map[nxt_y][nxt_x] <= '9') map[nxt_y][nxt_x] = map[nxt_y][nxt_x] + 1;
						else continue;
					}
				}
			}
		}

		// 결과 출력
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				map[i][j] = map[i][j] == '.' ? '0' : map[i][j];
				cout << map[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}