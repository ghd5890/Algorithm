#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words);

int main()
{
	vector<string> words;
	vector<int> answer;
	int n, words_cnt;
	
	cin >> n >> words_cnt;

	words = vector<string>(words_cnt);
	for (unsigned int i = 0; i < words.size(); i++) cin >> words[i];

	answer = solution(n, words);
	for (unsigned int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';
	cout << '\n';

	return 0;
}

vector<int> solution(int n, vector<string> words) 
{
	vector<int> answer;
	set<string> record;

	record.insert(words[0]);
	for (unsigned int i = 1; i < words.size(); i++)
	{
		if (record.find(words[i]) != record.end() || (words[i - 1].back() != words[i][0]))
		{
			answer.push_back((i % n) + 1);
			answer.push_back((i / n) + 1);
			break;
		}
		record.insert(words[i]);
	}

	if (answer.empty())
	{
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}