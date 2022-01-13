#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

enum
{
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
};

int main()
{
	vector<string> matrix;
	vector<int> square;
	int t, r, c, answer;

	cin >> t;
	while (t--)
	{
		cin >> r >> c;

		square = vector<int>(4, 0);

		matrix = vector<string>(r);
		for (int i = 0; i < r; i++) cin >> matrix[i];

		answer = 0;
		// 윗면과 아랫면의 면적을 구한다.
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) answer = matrix[i][j] != '0' ? answer + 1 : answer;
		}
		answer *= 2;

		// 북쪽의 면적
		for (int col = 0; col < c; col++)
		{
			square[NORTH] += (int)(matrix[0][col] - '0');
			for (int row = 1; row < r; row++)
			{
				square[NORTH] = matrix[row][col] > matrix[row - 1][col] ? square[NORTH] + (int)(matrix[row][col] - matrix[row - 1][col]) : square[NORTH];
			}
		}

		// 동쪽의 면적
		for (int row = 0; row < r; row++)
		{
			square[EAST] += (int)(matrix[row][c - 1] - '0');
			for (int col = c - 2; col >= 0; col--)
			{
				square[EAST] = matrix[row][col] > matrix[row][col + 1] ? square[EAST] + (int)(matrix[row][col] - matrix[row][col + 1]) : square[EAST];
			}
		}
		
		// 남쪽의 면적
		for (int col = 0; col < c; col++)
		{
			square[SOUTH] += (int)(matrix[r - 1][col] - '0');
			for (int row = r - 2; row >= 0; row--)
			{
				square[SOUTH] = matrix[row][col] > matrix[row + 1][col] ? square[SOUTH] + (int)(matrix[row][col] - matrix[row + 1][col]) : square[SOUTH];
			}
		}

		// 서쪽의 면적
		for (int row = 0; row < r; row++)
		{
			square[EAST] += (int)(matrix[row][0] - '0');
			for (int col = 1; col < c; col++)
			{
				square[EAST] = matrix[row][col] > matrix[row][col - 1] ? square[EAST] + (int)(matrix[row][col] - matrix[row][col - 1]) : square[EAST];
			}
		}

		for (int i = 0; i < 4; i++) answer += square[i];
		cout << answer << '\n';
	}

	return 0;
}