#include<stdio.h>
#define max 100
void shift_vector(int m,int *vector,int number)
{
    int a,v[m];
    a=number%m;
    if(a<0) a+=m;
    a=m-a;
    int i;
    for(i=0;i<m-1;i++)
    printf("%d ",*(vector+(a+i)%m));
    printf("%d",*(vector+(a+i)%m));
}
int main()
{
    int m,vect[max]={0},num;
    int *ptr;
    ptr=&vect[0];
    scanf("%d",&m);
    if(m<=0||m>=100)
    {
        printf("ERROR");
        return 0;
    }
    int i;
    for(i=0;i<m;i++)    scanf("%d",&vect[i]);
    scanf("%d",&num);
    shift_vector(m,ptr,num);
}