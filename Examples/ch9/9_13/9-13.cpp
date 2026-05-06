//9_13.cpp
#include <iostream>
#include "9_13.h"
using namespace std;
int main()
{
	int num[5] = { 8,5,2,4,3 };
	bubbleSort(num, 5);
	for (int& e : num)
	{
		cout << e << ' ';
	}
	cout << endl;
}
