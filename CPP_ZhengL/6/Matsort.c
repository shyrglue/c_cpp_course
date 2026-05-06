#include<stdio.h>
void order(int m, int n, int *matrix);
int main()
{
    int m,n,a[100][100],i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
    int *ma=a[0];
    order(m,n,ma);
}
void order(int m, int n, int *matrix)
{
    if (m<100&&m>0&&n<100&&n>0)
    {
        int sum[100],i,j,k,l;
        
        for(j=0;j<n;j++)
        {
            for(k=0;k<m-1;k++)
            {
            for(i=0;i<m-1-k;i++)
            {
                if(*(matrix+i*100+j)>*(matrix+i*100+100+j))
                {
                    *(matrix+i*100+j)+=*(matrix+i*100+100+j);
                    *(matrix+i*100+100+j)*=-1;
                    *(matrix+i*100+100+j)+=*(matrix+i*100+j);
                    *(matrix+i*100+j)+=-*(matrix+i*100+100+j);
                }
            }
            }
        }
        

        for(k=0;k<n-1;k++)
        {
        for(j=0;j<n-1-k;j++)
        {
            for(l=0;l<n;l++)
            {
            sum[l]=0;
            for(i=0;i<m;i++)
            sum[l]+=*(matrix+i*100+l);
            }
            if(sum[j]>sum[j+1])
            {
                for(i=0;i<m;i++)
                {
                    *(matrix+i*100+j)+=*(matrix+i*100+1+j);
                    *(matrix+i*100+1+j)*=-1;
                    *(matrix+i*100+1+j)+=*(matrix+i*100+j);
                    *(matrix+i*100+j)+=-*(matrix+i*100+1+j);
                }
            }
        }
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
            printf("%d ",*(matrix+i*100+j));
            printf("%d\n",*(matrix+i*100+j));
        }
    }
    else
    printf("ERROR");
}