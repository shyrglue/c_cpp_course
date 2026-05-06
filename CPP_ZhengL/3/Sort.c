#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    if (m<21&&m>0&&n<21&&n>0)
    {
        int a[20][20],sum[20],i,j,k,l;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<m;i++)
        {
            for(k=0;k<n-1;k++)
            {
            for(j=0;j<n-1-k;j++)
            {
                if(a[i][j]>a[i][j+1])
                {
                    a[i][j]+=a[i][j+1];
                    a[i][j+1]*=-1;
                    a[i][j+1]+=a[i][j];
                    a[i][j]+=-a[i][j+1];
                }
            }
            }
        }

        for(k=0;k<m-1;k++)
        {
        for(i=0;i<m-1-k;i++)
        {
            for(l=0;l<m;l++)
            {
            sum[l]=0;
            for(j=0;j<n;j++)
            sum[l]+=a[l][j];
            }
            if(sum[i]>sum[i+1])
            {
                for(j=0;j<n;j++)
                {
                    a[i][j]+=a[i+1][j];
                    a[i+1][j]*=-1;
                    a[i+1][j]+=a[i][j];
                    a[i][j]+=-a[i+1][j];
                }
            }
        }
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
            printf("%d ",a[i][j]);
            printf("%d\n",a[i][j]);
        }
    }
    else
    printf("error");
}