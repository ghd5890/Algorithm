/*
	프로그래머스 LEVEL 3(정수 삼각형)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> tirangle);

int main()
{
	vector<vector<int>> triangle; // 정수 삼각형
	int height; // 삼각형의 높이

	// 정수 삼각형의 입력
	cin >> height;
	triangle = vector<vector<int>>(height);

	for (int i = 0; i < height; i++)
	{
		triangle[i] = vector<int>(i + 1);
		for (int j = 0; j < i + 1; j++) cin >> triangle[i][j];
	}

	cout << solution(triangle) << '\n';

	return 0;
}

int solution(vector<vector<int>> triangle) 
{
	int answer = 0;
	vector<vector<int>> dp = vector<vector<int>>(triangle.size());
	for (int i = 0; i < triangle.size(); i++) dp[i] = vector<int>(i + 1, 0);

	dp[0][0] = triangle[0][0];
	for (int y = 1; y < triangle.size(); y++)
	{
		dp[y][0] = triangle[y][0] + dp[y - 1][0];
		dp[y][y] = triangle[y][y] + dp[y - 1][y - 1];
	}

	for (int y = 2; y < triangle.size(); y++)
	{
		for (int x = 1; x < y; x++)
		{
			dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + triangle[y][x];
		}
	}

	for (int i = 0; i < triangle.size(); i++)
	{
		answer = max(answer, dp[dp.size() - 1][i]);
	}

	return answer;
}