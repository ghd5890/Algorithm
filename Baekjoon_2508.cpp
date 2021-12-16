#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

/*
	사탕의 형태1 
		>o<
	사탕의 형태2 
		v
		o
		^
*/
char candy1[3] = { '>', 'o', '<' }; 
char candy2[3] = { 'v', 'o', '^' };

int main()
{
	vector<vector<char>> box;
	int t, r, c, count = 0;

	cin >> t;
	while (t--)
	{
		// 필요한 정보 입력(상자의 가로, 세로 크기 입력 && 박스의 내용물 입력)
		cin >> r >> c;
		box = vector<vector<char>>(r);
		for (UNS_INT i = 0; i < box.size(); i++)
		{
			box[i] = vector<char>(c);
			for (UNS_INT j = 0; j < box[i].size(); j++) cin >> box[i][j];
		}

		// 알고리즘의 동작
		for (UNS_INT row = 0; row < box.size(); row++)
		{
			for (UNS_INT col = 0; col < box[row].size(); col++)
			{
				bool check = true;
				if (box[row][col] == '>') // 사탕이 가로로 놓여있는지 확인
				{
					for (int next = col; next < col + 3; next++)
					{
						if ((0 <= next && next < box[row].size()) && candy1[next - col] == box[row][next]) continue;
						else
						{
							check = false;
							break;
						}
					}

					count = check ? count + 1 : count;
				}
				else if (box[row][col] == 'v') // 사탕이 세로로 놓여있는지 확인
				{
					for (int next = row; next < row + 3; next++)
					{
						if ((0 <= next && next < box.size()) && (candy2[next - row] == box[next][col])) continue;
						else
						{
							check = false;
							break;
						}
					}

					count = check ? count + 1 : count;
				}
				else continue; // 사탕이 아니면 다음으로 넘어가기
			}
		}

		cout << count << '\n';
		count = 0;
	}

	return 0;
}