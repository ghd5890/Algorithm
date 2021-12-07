#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef unsigned int UNS_INT;
int solution(vector<vector<int>> maps);

int main()
{
	vector<vector<int>> maps;
	int n, m;

	cin >> n >> m;
	maps = vector<vector<int>>(m);
	for (int i = 0; i < m; i++) maps[i] = vector<int>(n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) cin >> maps[i][j];

	cout << solution(maps) << '\n';

	return 0;
}

int solution(vector<vector<int>> maps)
{
	UNS_INT height = maps.size(), width = maps[0].size();
	vector<vector<int>> visited; // 방문 여부를 나타내는 벡터
	queue<pair<int, int>> q;
	int move_y[4] = { 1, -1, 0, 0 }; int move_x[4] = { 0, 0, 1, -1 };
	int answer = 0;

	visited = vector<vector<int>>(height);
	for (UNS_INT i = 0; i < height; i++)
		visited[i] = vector<int>(width, -1);

	visited[0][0] = 1;
	q.push(pair<int, int>(0, 0));

	int cur_y, cur_x, nxt_y, nxt_x;
	while (!q.empty())
	{
		cur_y = q.front().first; cur_x = q.front().second;
		for (int dir = 0; dir < 4; dir++)
		{
			nxt_y = cur_y + move_y[dir]; nxt_x = cur_x + move_x[dir];
			if ((0 <= nxt_y && nxt_y < height) && (0 <= nxt_x && nxt_x < width) && maps[nxt_y][nxt_x] == 1 && visited[nxt_y][nxt_x] == -1)
			{
				q.push(pair<int, int>(nxt_y, nxt_x));
				visited[nxt_y][nxt_x] = visited[cur_y][cur_x] + 1;
			}
		}
		q.pop();
	}

	answer = visited[height - 1][width - 1];

	return answer;
}