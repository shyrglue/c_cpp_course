#include <iostream>
using namespace std;
int main()
{
    int num, i = 0;
    cin >> num;
    for (; num / 10 != 0; num = i)
    {
        i = 0;
        do{
            i += num % 10;
            num /= 10;
        }while (num != 0);//提取每一位操作的扩展
    }
    cout << num;
}