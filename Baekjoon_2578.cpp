#include <iostream>
#include <vector>
#include <queue>
#define BOARD_SIZE 5
#define ROW 0
#define COL 1

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<vector<int>> board; // �����忡 ���� ���ڸ� �����Ѵ�.
	vector<vector<int>> input; // ��ȸ�ڰ� �θ��� ���� �����Ѵ�.
	vector<vector<int>> bingo_board;
	bool bingo = false;
	int answer = 0, count = 0, cnt = 0, input_row = 0, input_col = 0, board_row = 0, board_col = 0;

	bingo_board = vector<vector<int>>(2);
	for (UNS_INT i = 0; i < 2; i++) bingo_board[i] = vector<int>(BOARD_SIZE, 0);

	// �����忡 ���ڸ� �Է��Ѵ�.
	board = vector<vector<int>>(BOARD_SIZE);
	for (UNS_INT i = 0; i < BOARD_SIZE; i++)
	{
		board[i] = vector<int>(BOARD_SIZE);
		for (UNS_INT j = 0; j < BOARD_SIZE; j++) cin >> board[i][j];
	}

	// ��ȸ�ڰ� �θ��� ���� �Է��Ѵ�.
	input = vector<vector<int>>(BOARD_SIZE);
	for (UNS_INT i = 0; i < BOARD_SIZE; i++)
	{
		input[i] = vector<int>(BOARD_SIZE);
		for (UNS_INT j = 0; j < BOARD_SIZE; j++) cin >> input[i][j];
	}

	// �˰����� ����
	for (UNS_INT input_idx = 0; input_idx < BOARD_SIZE * BOARD_SIZE; input_idx++) // ��ȸ�ڰ� �θ��� ���� Ȯ���ϴ� ����
	{
		input_row = input_idx / BOARD_SIZE;
		input_col = input_idx % BOARD_SIZE;

		for (UNS_INT board_idx = 0; board_idx < BOARD_SIZE * BOARD_SIZE; board_idx++) // ���忡 ���� ���� Ȯ���ϴ� ����
		{
			board_row = board_idx / BOARD_SIZE;
			board_col = board_idx % BOARD_SIZE;

			if (board[board_row][board_col] == input[input_row][input_col])
			{
				answer++;

				count = 0;
				bingo_board[ROW][board_row] += 1;
				bingo_board[COL][board_col] += 1;
				board[board_row][board_col] = -1;

				// ���ο� ���θ� Ȯ��
				for (UNS_INT i = 0; i < BOARD_SIZE; i++)
				{
					count = bingo_board[ROW][i] == BOARD_SIZE ? count + 1 : count;
					count = bingo_board[COL][i] == BOARD_SIZE ? count + 1 : count;
				}

				// �밢�� ���� ������ �� Ȯ��
				cnt = 0;
				for (UNS_INT i = 0; i < BOARD_SIZE; i++) cnt = board[i][i] == -1 ? cnt + 1 : cnt;
				count = cnt == BOARD_SIZE ? count + 1 : count;

				cnt = 0;
				for (UNS_INT i = 0; i < BOARD_SIZE; i++) cnt = board[i][BOARD_SIZE - i - 1] == -1 ? cnt + 1 : cnt;
				count = cnt == BOARD_SIZE ? count + 1 : count;

				if (count >= 3)
				{
					bingo = true;
					break;
				}
			}
		}

		if (bingo) break;
	}

	cout << answer << '\n';

	return 0;
}