#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MAX 50

using namespace std;

typedef unsigned int UNS_INT;

int find(int* group, int a);
void merge(int* group, int a, int b);

int main()
{
	vector<string> words;
	int group[MAX] = { 0 };
	int n, start = 0, pos = 0, answer = 0;
	bool result = false;

	memset(group, -1, sizeof(group));

	cin >> n;

	words = vector<string>(n);
	for (UNS_INT i = 0; i < n; i++) cin >> words[i];

	for (UNS_INT cur = 0; cur < words.size(); cur++)
	{
		for (UNS_INT nxt = cur + 1; nxt < words.size(); nxt++)
		{
			if (cur == nxt || group[nxt] != -1 || words[cur].length() != words[nxt].length()) continue;
			if (find(group, cur) == find(group, nxt)) continue;

			// 현재단어의 첫번째 문자와 비교하는 단어에 일치하는 문자가 있는지 확인하고 위치를 알아낸다. 
			for (UNS_INT idx1 = 0; idx1 < words[cur].length(); idx1++)
			{
				if (words[nxt][idx1] == words[cur][0]) // 현재 단어의 첫번째 문자와 동일한 문자의 위치를 찾음
				{
					start = idx1;
					pos = start;
					result = true;
					for (UNS_INT idx2 = 0; idx2 < words[cur].length(); idx2++)
					{
						if (words[cur][idx2] != words[nxt][pos]) // 불일치할 경우
						{
							result = false;
							break;
						}
						pos = pos + 1 < words[nxt].length() ? pos + 1 : 0;
					}

					if (result)
					{
						merge(group, cur, nxt);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) answer = group[i] == -1 ? answer + 1 : answer;

	cout << answer << '\n';
	
	return 0;
}

int find(int* group, int a)
{
	if (group[a] < 0) return a;
	group[a] = find(group, group[a]);
	return group[a];
}

void merge(int* group, int a, int b)
{
	a = find(group, a);
	b = find(group, b);
	if (a == b) return;
	group[b] = a;

	return;
}