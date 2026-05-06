#include<stdio.h>
void shift_2d_matrix(int m, int n, int (*matrix)[100], int *number)
{
    int a;
    a=number[0]%n;
    if(a<0) a+=n;
    a=n-a;
    int b;
    b=number[1]%m;
    if(b<0) b+=m;
    b=m-b;
    int i=0;
    for(int j=1;j<=n;j++){
    for(;i<m*j-1;i++)
    printf("%d ",(*matrix)[(i/n+b)%m*n+(i%n+a)%n]);
    printf("%d\n",(*matrix)[(i/n+b)%m*n+(i%n+a)%n]);
    i++;}
}

int main()
{
    int m,n,i;
    scanf("%d %d",&m,&n);
    if(m<=0||m>=100||n<=0||n>=100)
    {
        printf("ERROR");
        return 0;
    }
    int a[100],b[2];
    for(i=0;i<m*n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<2;i++)
    scanf("%d",&b[i]);
    shift_2d_matrix(m,n,&a,b);
}