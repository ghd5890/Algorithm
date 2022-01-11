#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

// 나이가 많은 사람의 인덱스를 반환한다.
int solution(int a, int b, vector<vector<int>> date);

int main()
{
	vector<string> name;
	vector<vector<int>> date;
	int n, min_idx = 0, max_idx = 0, result, year, month, day;

	cin >> n;

	name = vector<string>(n);
	date = vector<vector<int>>(n);
	for (UNS_INT i = 0; i < n; i++) date[i] = vector<int>(3);

	for (UNS_INT i = 0; i < n; i++)
	{
		cin >> name[i] >> day >> month >> year;
		date[i][0] = year, date[i][1] = month, date[i][2] = day;
	}

	// 알고리즘의 동작
	for (int i = 1; i < n; i++)
	{
		result = solution(min_idx, i, date);
		min_idx = result == i ? min_idx : i;

		result = solution(max_idx, i, date);
		max_idx = result == i ? i : max_idx;
	}

	// 결과 출력
	cout << name[min_idx] << '\n' << name[max_idx] << '\n';

	return 0;
}

// 나이가 많은 사람의 인덱스를 반환한다.
int solution(int a, int b, vector<vector<int>> date)
{
	int answer = 0;

	for (int i = 0; i < 3; i++)
	{
		if (date[a][i] == date[b][i]) continue;
		answer = date[a][i] < date[b][i] ? a : b;
		break;
	}

	return answer;
}