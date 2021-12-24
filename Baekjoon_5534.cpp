#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<string> old_board;
	string signboard;
	stack<int> stk;
	int n, answer = 0;

	cin >> n;
	cin >> signboard;

	old_board = vector<string>(n);
	for (UNS_INT i = 0; i < old_board.size(); i++) cin >> old_board[i];

	UNS_INT jump = 0, src = 0, sb_idx = 0, tmp_idx = 0;
	vector<bool> result_arr = vector<bool>(n, false);
	bool result = true;

	for (UNS_INT i = 0; i < old_board.size(); i++)
	{
		for (UNS_INT ob_idx = 0; ob_idx < old_board[i].length(); ob_idx++) // 오래된 간판의 이름을 탐색한다.
		{
			if (old_board[i][ob_idx] == signboard[0]) // 오래된 간판의 글자 중 가게 이름의 첫번째 글자와 같은 경우
			{
				src = ob_idx;
				for (UNS_INT pos = ob_idx + 1; pos < old_board[i].length(); pos++) if (old_board[i][pos] == signboard[1]) stk.push(pos);

				while (!stk.empty())
				{
					result = true;
					sb_idx = 0;
					jump = stk.top() - src;
					tmp_idx = src;

					while (tmp_idx < old_board[i].length())
					{
						if (sb_idx < signboard.length() && signboard[sb_idx] != old_board[i][tmp_idx])
						{
							result = false;
							break;
						}

						tmp_idx += jump;
						sb_idx++;
					}


					if (result && sb_idx >= signboard.length())
					{
						result_arr[i] = result_arr[i] || result;
						while (!stk.empty()) stk.pop();
						break;
					}

					stk.pop();
				}
			}
		}
	}

	for (UNS_INT i = 0; i < result_arr.size(); i++) answer = result_arr[i] ? answer + 1 : answer;

	cout << answer << '\n';

	return 0;
}