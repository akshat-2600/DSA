// T.C : O(1)
// S.C : O(1)

#include <iostream>
using namespace std;

int main()
{
	bool flag = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int val;
			cin >> val;
			if (val == 1) {
				int x = abs(2 - i);
				int y = abs(2 - j);
				flag = true;
				cout << x+y;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
}