#include<stdio.h>
void input(int*n,int N[][2],int*m,int M[][2])
{
    int i;
    scanf("%d",n);
    for(i=0;i<(*n);i++)
    scanf("%d %d",&(N[i][0]),&(N[i][1]));
    scanf("%d",m);
    for(i=0;i<(*m);i++)
    scanf("%d %d",&(M[i][0]),&(M[i][1]));
}

void combine(int M[][2],int N[][2],int m,int n,int*p)
{   
    int i,j;
    int t;
    for(i=0;i<n;i++)
    {
        M[m+i][0]=N[i][0];
        M[m+i][1]=N[i][1];
    }
    for(i=0;i<m+n-1;i++)
    {
        for(j=0;j<m+n-1-i;j++)
        {
            if(M[j][0]>M[j+1][0])
            {
                t=M[j][0];
                M[j][0]=M[j+1][0];
                M[j+1][0]=t;
                t=M[j][1];
                M[j][1]=M[j+1][1];
                M[j+1][1]=t;
            }
        }
    }
    for(i=0;i<m+n-1;i++)
    {
        if(M[i][0]==M[i+1][0])
        {
            M[i][1]=(M[i][1]+M[i+1][1])/2;
            M[i+1][0]=0;
        }
    }
    M[m+n][0]=-1;
    for(i=0;i<m+n;i++)
    {
        if(M[i][0]==0)
        {
            for(j=i;;j++)
            {
                M[j][0]=M[j+1][0];
                M[j][1]=M[j+1][1];
                if(M[j][0]==-1) break;
            }
            M[j][0]=-1;
        }
    }
    (*p)=j;
}   
void print(int m[][2],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",m[i][0]);
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d ",m[i][1]);
}
void area(int m[][2],int n)
{
    int i;
    double S=0;
    for(i=0;i<n-1;i++)
    S+=(double)((m[i][1]+m[i+1][1])*(m[i+1][0]-m[i][0]))/2;
    printf("\n%.2lf",S);
}
int main()
{
    int m,n,M[100][2]={0},N[100][2]={0},**Q,p;
    input(&m,M,&n,N);
    combine(M,N,m,n,&p);
    print(M,p);
    area(M,p);
    return 0;
}