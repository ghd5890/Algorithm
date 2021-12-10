#include <iostream>
#include <string>
#include <vector>

using namespace std;

string number_output(int n, int num);
string solution(int n, int t, int m, int p);

int main()
{
	int n, t, m, p;

	cin >> n >> t >> m >> p;

	cout << solution(n, t, m, p) << '\n';

	return 0;
}

string number_output(int n, int num) // ���ڸ� n�������� �ٲٴ� �Լ�
{
	string answer = "";
	int mod = 0;
	char add = ' ';

	if (num == 0) answer = "0";
	while (num != 0)
	{
		mod = num % n;
		add = (mod >= 10) ? (char) ((mod % 10) + 'A') : (char) mod + '0';
		answer = add + answer;
		num /= n;
	}

	return answer;
}

string solution(int n, int t, int m, int p)
{
	string answer = "", cur_number = "";
	int turn = 1;
	int number = 0;

	while (answer.length() != t)
	{
		cur_number = number_output(n, number);
		while (cur_number.length() != 0)
		{
			answer = (turn == p) ? answer + cur_number[0] : answer; // ���� Ʃ���� ������ ��� ���ڸ� ���̰� �ƴϸ� ���ڸ� ������ �ʴ´�.
			// ���� ������ �̵�
			turn = (turn + 1) % m == 0 ? m : (turn + 1) % m;
			cur_number = cur_number.substr(1);
			if (answer.length() == t) break;
		}
		number++;
	}

	return answer;
}