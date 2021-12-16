#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

/*
	������ ����1 
		>o<
	������ ����2 
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
		// �ʿ��� ���� �Է�(������ ����, ���� ũ�� �Է� && �ڽ��� ���빰 �Է�)
		cin >> r >> c;
		box = vector<vector<char>>(r);
		for (UNS_INT i = 0; i < box.size(); i++)
		{
			box[i] = vector<char>(c);
			for (UNS_INT j = 0; j < box[i].size(); j++) cin >> box[i][j];
		}

		// �˰����� ����
		for (UNS_INT row = 0; row < box.size(); row++)
		{
			for (UNS_INT col = 0; col < box[row].size(); col++)
			{
				bool check = true;
				if (box[row][col] == '>') // ������ ���η� �����ִ��� Ȯ��
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
				else if (box[row][col] == 'v') // ������ ���η� �����ִ��� Ȯ��
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
				else continue; // ������ �ƴϸ� �������� �Ѿ��
			}
		}

		cout << count << '\n';
		count = 0;
	}

	return 0;
}