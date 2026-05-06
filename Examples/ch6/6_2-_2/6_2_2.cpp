//6_2.cpp
#include <iostream>
using namespace std;
void rowSum(const int a[][4], int nRow, int s[]) {    //计算二维数组A每行元素的值的和，nrow是行数
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < 4; j++)
			s[i] += a[i][j];
	}
}
int main() {	//主函数
	int table[3][4] = { {1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6} };//声明并初始化数组
	int sum[3] = { 0 };
	for (int i = 0; i < 3; i++) { //输出数组元素
		for (int j = 0; j < 4; j++)
			cout << table[i][j] << "   ";
		cout << endl;
	}
	rowSum(table, 3, sum);	//调用子函数，计算各行和
	for (int i = 0; i < 3; i++)	//输出计算结果
		cout << "Sum of row " << i << " is " << sum[i] << endl;
	return 0;
}
