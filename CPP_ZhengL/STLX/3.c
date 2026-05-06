#include<stdio.h>
#include<ctype.h>
struct STUDENT
{
    char name[20];
    int age;
}stu;
void Input()
{
    char a;int b;
    for(int i=0;;i++)
    {
        a=getchar();
        if(isdigit(a)) break;
        else stu.name[i]=a;
    }
    scanf("%d",&b);
    stu.age=b+10*(a-'0');
}
void Output(struct STUDENT stu)
{
    printf("%s%d",stu.name,stu.age);
}
int main()
{
    Input();
    Output(stu);
}