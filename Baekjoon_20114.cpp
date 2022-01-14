#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<string> sentence;
	vector<char> answer;
	int n, h, w;
	char c;

	cin >> n >> h >> w;

	answer = vector<char>(n, '?');
	sentence = vector<string>(h);
	for (UNS_INT i = 0; i < h; i++) cin >> sentence[i];

	for (UNS_INT row = 0; row < sentence.size(); row++)
	{
		for (UNS_INT col = 0; col < sentence[row].length(); col += w)
		{
			for (UNS_INT idx = 0; idx < w; idx++)
			{
				if (sentence[row][col + idx] != '?') answer[col / w] = sentence[row][col + idx];
			}
		}
	}

	for (UNS_INT idx = 0; idx < answer.size(); idx++) cout << answer[idx];
	cout << '\n';

	return 0;
}