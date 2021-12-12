#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right);

int main()
{
	vector<int> answer;
	int n;
	long long left, right;

	cin >> n >> left >> right;

	answer = solution(n, left, right);

	for (unsigned int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';
	cout << '\n';

	return 0;
}

vector<int> solution(int n, long long left, long long right)
{
	vector<int> answer;
	long long row = 0, col = 0, data = 0;

	row = left / n;
	col = left - (row * n);
	
	while (1)
	{
		if ((row * n) + col > right) break;

		data = (row >= col) ? row + 1 : col + 1;
		answer.push_back(data);
		// 다음 칸으로 이동
		row = col + 1 == n ? row + 1 : row;
		col = (col + 1) % n;
	}

	return answer;
}