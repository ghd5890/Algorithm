#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define MAX 10

using namespace std;

typedef unsigned int UNS_INT;

int solution(string dirs);

int main()
{
	string dirs;

	cin >> dirs;

	cout << solution(dirs) << '\n';

	return 0;
}

int solution(string dirs)
{
	int answer = 0, cur_y = 5, cur_x = 5, nxt_y = 0, nxt_x = 0, m = 0, step = 0, overlap = 0; 
	int move_y[4] = { 1, 0, -1, 0 }, move_x[4] = { 0, 1, 0, -1 };
	char visited[MAX + 1][MAX + 1];

	memset(visited, 0, sizeof(visited));

	for (UNS_INT d = 0; d < dirs.length(); d++)
	{
		switch (dirs[d])
		{
		case 'U':
		{
			m = 0;
			break;
		}
		case 'L':
		{
			m = 1;
			break;
		}
		case 'D':
		{
			m = 2;
			break;
		}
		case 'R':
		{
			m = 3;
			break;
		}
		default:break;
		}

		nxt_y = cur_y + move_y[m]; nxt_x = cur_x + move_x[m];
		if ((0 <= nxt_y && nxt_y <= MAX) && (0 <= nxt_x && nxt_x <= MAX)) // 다음 좌표가 이동할 수 있는 범위에 있을 경우
		{
			int check = (visited[cur_y][cur_x] & (1 << m));
			overlap = check == 0 ? overlap : overlap + 1; // 현재 이동한 방향으로 이동했던 경로인지 확인한다.
			visited[nxt_y][nxt_x] = (visited[nxt_y][nxt_x] | (1 << ((m + 2) % 4))); // 현재위치에서 다음 위치로 어느 방향으로 왔는 지 체크
			visited[cur_y][cur_x] = (visited[cur_y][cur_x] | (1 << m)); // 현재 위치에서 이동한 방향 체크
			cur_y = nxt_y; cur_x = nxt_x;

			step++;
		}
	}
	answer = step - overlap;
	return answer;
}