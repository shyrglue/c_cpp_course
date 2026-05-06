#include<stdio.h>

void transpose(int m,int n,int(*matrix)[100])
{
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<m-1;j++)
        printf("%d ",(*matrix)[j*n+i]);
        printf("%d\n",(*matrix)[j*n+i]);
    }
}
void multiply(int m, int n,  int p, int q, int (*matrix1)[100], int (*matrix2)[100])
{
    if(q!=n) printf("INVALID");
    else{
        int i,j,k,t;
        for(i=0;i<m;i++)
        {
            for(j=0;j<p-1;j++)
            {
                t=0;
                for(k=0;k<n;k++)
                t+=(*matrix1)[i*n+k]*(*matrix2)[j*q+k];
                printf("%d ",t);
            }
                t=0;
                for(k=0;k<n;k++)
                t+=(*matrix1)[i*n+k]*(*matrix2)[j*q+k];
                printf("%d\n",t);
        }
    }
}
int main()
{
    int m,n,p,q,i,j;
    scanf("%d%d%d%d",&m,&n,&p,&q);
    if(p<=0||p>=100||q<=0||q>=100||m<=0||m>=100||n<=0||n>=100) {
        printf("ERROR");
        return 0;
    }
    int a[100]={0},b[100]={0};
    for(i=0;i<m*n;i++) scanf("%d",&a[i]);
    for(i=0;i<p*q;i++) scanf("%d",&b[i]);
    transpose(p,q,&b);
    multiply(m,n,p,q,&a,&b);
}