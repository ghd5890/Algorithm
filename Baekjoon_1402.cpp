#include <iostream>
#include <vector>
#include <string>
#define INF 1000

using namespace std;

typedef unsigned int UNS_INT;

int map[INF][INF] = { 0 };

int main()
{
	vector<string> board;
	int n;

	cin >> n;
	board = vector<string>(n);
	for (UNS_INT i = 0; i < board.size(); i++) cin >> board[i];

	int nxt_y = 0, nxt_x = 0, mine = 0, tmp = 0;
	int move_y[8] = { 1, -1, 0, 0 , -1, 1, 1, -1}; int move_x[8] = { 0, 0, 1, -1, 1, 1, -1, -1};

	for (UNS_INT row = 0; row < board.size(); row++)
	{
		for (UNS_INT col = 0; col < board[row].size(); col++)
		{
			if (board[row][col] == '.') continue;
			mine = board[row][col] - '0';
			for (UNS_INT dir = 0; dir < 8; dir++)
			{
				nxt_y = row + move_y[dir]; nxt_x = col + move_x[dir];
				if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= n) continue;
				map[nxt_y][nxt_x] += mine;
			}
		}
	}

	for (UNS_INT row = 0; row < board.size(); row++)
	{
		for (UNS_INT col = 0; col < board[row].size(); col++)
		{
			if (board[row][col] != '.') cout << '*';
			else if (map[row][col] >= 10) cout << 'M';
			else cout << map[row][col];
		}
		cout << '\n';
	}

	return 0;
}