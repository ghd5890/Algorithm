#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1, r1, x2, y2, r2, len;
	bool check = false;

	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;

	len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // �� ���� �߽� ������ �Ÿ�

	/*
		1. �ϳ��� ���� �ٸ� ���� �����ϴ� ��� (len + r1 == r2) || (len + r2 == r1)
		2. �� ���� ��ġ�� �κ��� �����ϴ� ��� (len < r1 + r2)
		3. �ϳ��� ���� �ٸ� �� �ȿ� �����ϴ� ��� (len < r1 || len < r2) 
	*/
	if ((len + r1 == r2) || (len + r2 == r1)) check = true;
	if (len < r1 + r2) check = true;
	if (len < r1 || len < r2) check = true;

	if (check) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}