#include<stdio.h>
int main()
#define max 10000
{
    int N,S,K[max],M[max],monkey[max];
    scanf("%d%d",&N,&S);
    int i,j,k,l,m;
    for(i=0;i<S;i++)
    {
        scanf("%d%d",&K[i],&M[i]);
    }
    for(i=0;i<S;i++)
    {
        for(j=0;j<N;j++)
        {
            monkey[j]=j;
        }
        k=N;
        l=K[i]-1;
        m=1;
        while (k>1)
        {
            if(monkey[l]==-1)
                l=(l+1)%N;
            else
            {
                if(m==M[i])
                {
                    monkey[l]=-1;
                    m=1;
                    k--;
                }
                else
                {
                    m++;
                }
                l=(l+1)%N;
            }
        }
        for(j=0;j<N;j++)
        {
            if (monkey[j]!=-1)
            printf("%d\n",monkey[j]+1);
        }
    }
}