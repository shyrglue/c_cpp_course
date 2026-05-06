#include<stdio.h>
#define max 100
void shift_solit_matrix(int m,int n,int *matrix,int number)
{
    int t;
    for(int i=1;i<m;i+=2)
    {
        for(int j=0;2*j<n;j++)
        {
            t=*(matrix+i*n+j);
            *(matrix+i*n+j)=*(matrix+i*n+n-j-1);
            *(matrix+i*n+n-j-1)=t;
        }
    }

    
    int a;
    a=number%(m*n);
    if(a<0) a+=m*n;
    a=m*n-a;
    int i;
    for(i=0;i<m*n;i++)
    {
        if(i/n==i/n/2*2)
        {
            if(i+1==(i+1)/n*n) printf("%d\n",*(matrix+(a+i)%(m*n)));
            else printf("%d ",*(matrix+(a+i)%(m*n)));
        }
        else{
            if(i+1==(i+1)/n*n) printf("%d\n",*(matrix+(a+n-1-(i)%n+(i)/n*n)%(m*n)));
            else printf("%d ",*(matrix+(a+n-1-(i)%n+(i)/n*n)%(m*n)));
        }
    }
}
int main()
{
    int m,n,num,i,j;
    scanf("%d %d",&m,&n);
    if(m<=0||m>=100||n<=0||n>=100)
    {
        printf("ERROR");
        return 0;
    }
    int a[m][n];
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
    scanf("%d",&num);
    shift_solit_matrix(m,n,a[0],num);
}