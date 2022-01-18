#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define SIDE 4
#define PATTERN 5

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	/*
		n : â���� ����
		m : ����Ʈ�� ����
	*/
	vector<string> window;
	int answer[PATTERN] = { 0 };
	int n, m, cnt;
	char pattern[PATTERN][SIDE][SIDE + 1] =
	{
		// 1�� ����
		{
			"....",
			"....",
			"....",
			"...."
		},
		// 2�� ����
		{
			"****",
			"....",
			"....",
			"...."
		},
		// 3�� ����
		{
			"****",
			"****",
			"....",
			"...."
		},
		// 4�� ����
		{
			"****",
			"****",
			"****",
			"...."
		},
		// 5�� ����
		{
			"****",
			"****",
			"****",
			"****"
		}
	};

	// â���� ����, ����Ʈ�� ������ �Է�
	cin >> n >> m;
	// â���� ���� �Է�
	window = vector<string>((5 * n) + 1);
	for (UNS_INT row = 0; row < window.size(); row++) cin >> window[row];

	// �˰��� ����
	for (UNS_INT row = 1; row < window.size(); row += PATTERN)
	{
		for (UNS_INT col = 1; col < window[row].size(); col += PATTERN)
		{
			cnt = 0;
			
			for (UNS_INT r_idx = row; r_idx < row + SIDE; r_idx++)
			{
				for (UNS_INT c_idx = col; c_idx < col + SIDE; c_idx++)
				{
					if (window[r_idx][c_idx] == '*') cnt++;
					else break;
				}
			}

			answer[cnt / SIDE] += 1;
		}
	}

	// ��� ���
	for (int i = 0; i < 5; i++) cout << answer[i] << ' ';
	cout << '\n';

	return 0;
}