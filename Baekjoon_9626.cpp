#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{ 
	vector<string> puzzle;
	vector<vector<char>> chess;
	int m, n, u, l, r, d, chess_row, chess_col;
	char pattern = ' ';

	cin >> m >> n;
	cin >> u >> l >> r >> d;
	
	puzzle = vector<string>(m);
	for (UNS_INT i = 0; i < m; i++) cin >> puzzle[i];

	chess_row = m + u + d; chess_col = n + l + r;

	// 알고리즘의 동작
	chess = vector<vector<char>>(chess_row);
	for (UNS_INT row = 0; row < chess_row; row++) chess[row] = vector<char>(chess_col);

	for (UNS_INT row = 0; row < chess_row; row++)
	{
		for (UNS_INT col = 0; col < chess_col; col++)
		{
			if (row % 2) pattern = (col % 2 == 1) ? '#' : '.';
			else pattern = (col % 2 == 1) ? '.' : '#';

			if ((row >= u && row < chess_row - d) && (col >= l && col < chess_col - r)) chess[row][col] = puzzle[row - u][col - l];
			else chess[row][col] = pattern;
		}
	}

	// 결과 출력
	for (UNS_INT row = 0; row < chess_row; row++)
	{
		for (UNS_INT col = 0; col < chess_col; col++) cout << chess[row][col];
		cout << '\n';
	}

	return 0;
}