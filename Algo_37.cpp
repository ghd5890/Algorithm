#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define COLUMN 4

using namespace std;

vector<vector<int>> dp;
int dp_active(int row, int col, vector<vector<int>> land);
int solution(vector<vector<int>> land);

int main()
{
	vector<vector<int>> land;
	int n;

	cin >> n;
	land = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) land[i] = vector<int>(COLUMN);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < COLUMN; j++) cin >> land[i][j];

	dp = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) dp[i] = vector<int>(COLUMN, -1);

	cout << solution(land) << '\n';

	return 0;
}

int dp_active(int row, int col, vector<vector<int>> land)
{
	if (row >= land.size()) return 0;
	if (row == land.size() - 1) return dp[row][col] = land[row][col];
	int& ans = dp[row][col];
	if (ans != -1) return ans;
	for (int i = 0; i < COLUMN; i++)
	{
		if (i != col) ans = max(ans, dp_active(row + 1, i, land) + land[row][col]);
	}

	return ans;
}

int solution(vector<vector<int>> land)
{
	int answer = 0;

	for(int i = 0; i < COLUMN; i++) answer = dp_active(0, i, land);

	return answer;
}