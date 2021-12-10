#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef unsigned int UNS_INT;

enum ActionType
{
	ENTER = 0,
	LEAVE,
	CHANGE
};

vector<string> solution(vector<string> recod);

int main()
{
	vector<string> record, result;
	int n = 0;

	cin >> n;
	cin.ignore();
	record = vector<string>(n);
	for (UNS_INT i = 0; i < record.size(); i++) getline(cin, record[i]);

	result = solution(record);

	for (UNS_INT i = 0; i < result.size(); i++) cout << result[i] << '\n';

	return 0;
}

vector<string> solution(vector<string> record)
{
	vector<string> answer; vector<pair<string, ActionType>> action_record;
	map<string, string> uid_to_nickname;
	string action = "", uid = "", nickname = "";
	int blank_idx = 0, act_num = 0;

	for (UNS_INT i = 0; i < record.size(); i++)
	{
		blank_idx = record[i].find(' ');
		if (record[i][0] == 'E') // 채팅방 입장하기
		{
			// uid 추출
			record[i] = record[i].substr(blank_idx + 1);
			blank_idx = record[i].find(' ');
			uid = record[i].substr(0, blank_idx);
			// 닉네임 추출
			record[i] = record[i].substr(blank_idx + 1);
			nickname = record[i];

			if (uid_to_nickname.find(uid) == uid_to_nickname.end()) uid_to_nickname.insert(pair<string, string>(uid, nickname));
			else uid_to_nickname[uid] = nickname;

			action_record.push_back(pair<string, ActionType>(uid, ENTER));
		}
		else if (record[i][0] == 'L') // 채팅방 떠나기
		{
			uid = record[i].substr(blank_idx + 1);
			action_record.push_back(pair<string, ActionType>(uid, LEAVE));
		}
		else // 닉네임 변경
		{
			// uid 추출
			record[i] = record[i].substr(blank_idx + 1);
			blank_idx = record[i].find(' ');
			uid = record[i].substr(0, blank_idx);
			// 닉네임 추출
			record[i] = record[i].substr(blank_idx + 1);
			nickname = record[i];

			if (uid_to_nickname.find(uid) == uid_to_nickname.end()) uid_to_nickname.insert(pair<string, string>(uid, nickname));

			uid_to_nickname[uid] = nickname;
			action_record.push_back(pair<string, ActionType>(uid, CHANGE));
		}
	}

	for (UNS_INT i = 0; i < action_record.size(); i++)
	{
		switch (action_record[i].second)
		{
		case ENTER:
		{
			answer.push_back(uid_to_nickname[action_record[i].first] + "님이 들어왔습니다.");
			break;
		}
		case LEAVE:
		{
			answer.push_back(uid_to_nickname[action_record[i].first] + "님이 나갔습니다.");
			break;
		}
		case CHANGE:
		{
			break;
		}
	    default: break;
		}
	}
	
	return answer;
}