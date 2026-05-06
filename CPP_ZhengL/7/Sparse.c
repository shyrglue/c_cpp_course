#include<stdio.h>
void input(int m[][10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%d,",&m[i][j]);
        }
    }
}
int main()
{
    int m1[10][10]={0},m2[10][10]={0},i,j,m=0,rank[100]={0};
    input(m1);
    input(m2);
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++){
            m1[i][j]+=m2[i][j];
        if(m1[i][j]!=0)
        {
            rank[m]=m1[i][j];
            m++;
        }}
    }
    int t;
    for(i=0;i<m-1;i++)
    {
        for(j=i;j<m;j++)
        {
            if(rank[j]>rank[i])
            {
                t=rank[j];
                rank[j]=rank[i];
                rank[i]=t;
            }
        }
    }
    m/=2;
    if(m%2==0) m--;
    t=0;
    for(i=9;i>=0;i--)
    {
        for(j=9;j>=0;j--)
        {
            if(m1[j][i]==rank[m])
            {
                t=1;
                break;
            }
        }
        if(t) break;
    }

    printf("%d,%d,%d",rank[m],j+1,i+1);
}