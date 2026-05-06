#include<stdio.h>
#include<malloc.h>
struct A
{
    char char1;
    char char2;
    char char3[10];
}a;

void Input()
{
    a.char1=getchar();
    scanf("%c",&(a.char2));
    scanf("%s",&(a.char3));
}
void Output(struct A a)
{
    printf("%c,%c,%s",a.char1,a.char2,a.char3);
}
int main()
{
    Input();
    Output(a);
}