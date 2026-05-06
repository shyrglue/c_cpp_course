//2_4.cpp
#include <iostream>
using namespace std;

int main() {
	int day;

	cin >> day;
	switch (day) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		cout << "workday" << endl;
		break;
	case 0:
	case 6:
		cout << "Weekend" << endl;
		break;
	default:
		cout << "Day out of range Sunday .. Saturday" << endl;
		break;
	}

	return 0;
}
