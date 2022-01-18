#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1, r1, x2, y2, r2, len;
	bool check = false;

	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;

	len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // 두 원의 중심 사이의 거리

	/*
		1. 하나의 원이 다른 원에 내접하는 경우 (len + r1 == r2) || (len + r2 == r1)
		2. 두 원이 겹치는 부분이 존재하는 경우 (len < r1 + r2)
		3. 하나의 원이 다른 원 안에 존재하는 경우 (len < r1 || len < r2) 
	*/
	if ((len + r1 == r2) || (len + r2 == r1)) check = true;
	if (len < r1 + r2) check = true;
	if (len < r1 || len < r2) check = true;

	if (check) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}