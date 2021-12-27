#include <iostream>
#include <vector>
#include <set>
#define CARD 10

using namespace std;

typedef unsigned int UNS_INT;

set<int> number;
vector<bool> used;

void solution(int k, vector<int> picked, vector<int> cards);

int main()
{
	vector<int> cards, picked;
	int n, k;

	cin >> n;
	cin >> k;

	used = vector<bool>(n, false);
	cards = vector<int>(n);
	for (UNS_INT i = 0; i < cards.size(); i++) cin >> cards[i];

	solution(k, picked, cards);

	cout << number.size() << '\n';

	return 0;
}

void solution(int k, vector<int> picked, vector<int> cards)
{
	int share = 0, mul = 1, result = 0;

	if (picked.size() == k)
	{
		for (UNS_INT i = 0; i < picked.size(); i++)
		{
			share = picked[i] / CARD;
			mul = share == 0 ? 10 : 100;
			result *= mul;
			result += (picked[i]);
		}

		if(number.find(result) == number.end()) number.insert(result);

		return;
	}

	for (UNS_INT card = 0; card < cards.size(); card++)
	{
		if (!used[card])
		{
			used[card] = true;
			picked.push_back(cards[card]);
			solution(k, picked, cards);
			picked.pop_back();
			used[card] = false;
		}
	}

	return;
}