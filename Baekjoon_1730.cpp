#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<vector<char>> board;
	map<char, int> direction;
	string command;
	int move_y[4] = { -1, 1, 0, 0 }; int move_x[4] = { 0, 0, -1, 1 };
	int n;
	
	direction.insert(pair<char, int>('U', 0));
	direction.insert(pair<char, int>('D', 1));
	direction.insert(pair<char, int>('L', 2));
	direction.insert(pair<char, int>('R', 3));

	cin >> n;
	cin >> command;
	
	board = vector<vector<char>>(n);
	for (UNS_INT i = 0; i < board.size(); i++) board[i] = vector<char>(n, '.');

	int dir = 0, cur_y = 0, cur_x = 0, nxt_y = 0, nxt_x = 0;
	for (UNS_INT c = 0; c < command.length(); c++)
	{
		dir = direction[command[c]];
		nxt_y = cur_y + move_y[dir]; nxt_x = cur_x + move_x[dir];

		if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= n) continue; // 격자 밖일 경우 다음 명령으로 넘어가기

		if (board[cur_y][cur_x] == '.') board[cur_y][cur_x] = (dir == 0 || dir == 1) ? '|' : '-';
		else if (board[cur_y][cur_x] == '-') board[cur_y][cur_x] = (dir == 0 || dir == 1) ? '+' : board[cur_y][cur_x];
		else if (board[cur_y][cur_x] == '|') board[cur_y][cur_x] = (dir == 2 || dir == 3) ? '+' : board[cur_y][cur_x];
		
		if (board[nxt_y][nxt_x] == '.') board[nxt_y][nxt_x] = (dir == 0 || dir == 1) ? '|' : '-';
		else if (board[nxt_y][nxt_x] == '-') board[nxt_y][nxt_x] = (dir == 0 || dir == 1) ? '+' : board[nxt_y][nxt_x];
		else if (board[nxt_y][nxt_x] == '|') board[nxt_y][nxt_x] = (dir == 2 || dir == 3) ? '+' : board[nxt_y][nxt_x];

		cur_y = nxt_y; cur_x = nxt_x;
	}

	for (UNS_INT i = 0; i < board.size(); i++)
	{
		for (UNS_INT j = 0; j < board[i].size(); j++) cout << board[i][j];
		cout << '\n';
	}

	return 0;
}