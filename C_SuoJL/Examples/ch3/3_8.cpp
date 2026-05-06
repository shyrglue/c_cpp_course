//3_8.cpp
#include <iostream>
using namespace std;

//计算n的阶乘
unsigned fac(unsigned n) {
	unsigned f;
	if (n == 0)
		f = 1;
	else
		f = fac(n - 1) * n;
	return f;
}

int main() {
	unsigned n = 0, y = 0;
	cout << "Enter a positive integer: ";
	cin >> n;
	y = fac(n);
	cout << n << "! = " << y << endl;
	return 0;
}
