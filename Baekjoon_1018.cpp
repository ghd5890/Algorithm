#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define BOARD_SIZE 8
#define INF 100

using namespace std;

typedef unsigned int UNS_INT;

int solution(char color, vector<string> board);

int main()
{
	vector<string> board;
	vector<string> tmp_board;
	int n, m, answer = INF;

	// 보드의 행과 열의 크기를 입력
	cin >> n >> m;
	// 보드의 상태 입력
	board = vector<string>(n);
	for (UNS_INT i = 0; i < board.size(); i++) cin >> board[i];

	// 보드를 탐색한다.
	for (UNS_INT row = 0; row < board.size() - BOARD_SIZE + 1; row++)
	{
		for (UNS_INT col = 0; col < board[row].size() - BOARD_SIZE + 1; col++)
		{
			// tmp_board 생성
			tmp_board = vector<string>(BOARD_SIZE);
			for (UNS_INT i = 0; i < BOARD_SIZE; i++)
			{
				for (UNS_INT j = 0; j < BOARD_SIZE; j++) tmp_board[i] += board[row + i][col + j];
			}

			answer = min(answer, solution('B', tmp_board));

			tmp_board = vector<string>(BOARD_SIZE);
			for (UNS_INT i = 0; i < BOARD_SIZE; i++)
			{
				for (UNS_INT j = 0; j < BOARD_SIZE; j++) tmp_board[i] += board[row + i][col + j];
			}

			answer = min(answer, solution('W', tmp_board));
		}
	}

	cout << answer << '\n';

	return 0;
}

int solution(char color, vector<string> board)
{
	int answer = 0, prev_y, prev_x;
	char prev_color[2], tmp;
	int move_y[2] = { -1, 0 }, move_x[2] = { 0, -1 };

	answer = board[0][0] != color ? answer + 1 : answer;
	board[0][0] = color;
	
	for (UNS_INT row = 0; row < board.size(); row++)
	{
		for (UNS_INT col = 0; col < board[row].size(); col++)
		{
			for (UNS_INT i = 0; i < 2; i++)
			{
				prev_y = row + move_y[i]; prev_x = col + move_x[i];
				if (prev_y < 0 || prev_y >= BOARD_SIZE || prev_x < 0 || prev_x >= BOARD_SIZE)
				{
					prev_color[i] = 0;
					continue;
				}
				prev_color[i] = board[prev_y][prev_x];
			}

			tmp = prev_color[0] | prev_color[1];
			if (tmp == board[row][col] && tmp != 0)
			{
				board[row][col] = tmp == 'B' ? 'W' : 'B';
				answer++;
			}
		}
	}

	return answer;
}