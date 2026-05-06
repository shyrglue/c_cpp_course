#include<stdio.h>
#include<string.h>
#define max 255
int Longest_substring(char s1[256], char s2[256], char s3[256], char *buffer)
{
    int i,l1=0,l2=1,l3=1,j=0;
    char S1[max][max],S2[max][max],S3[max][max];
    for(i=0;i<strlen(s1);i++)
    {
        if(s1[i]==' ')
        {
            l1++;
            j=0;
            continue;
        }
        else
        {
        S1[l1][j]=s1[i];
        j++;
        }
    }
    j=0;
    for(i=0;i<strlen(s2);i++)
    {
        if(s2[i]==' ')
        {
            l2++;
            j=0;
            continue;
        }
        else
        {
        S2[l2][j]=s2[i];
        j++;
        }
    }
    j=0;
    for(i=0;i<strlen(s3);i++)
    {
        if(s3[i]==' ')
        {
            l3++;
            j=0;
            continue;
        }
        else
        {
        S3[l3][j]=s3[i];
        j++;
        }
    }
    int k,m=0;
    char S[max][max];
    for(i=0;i<l1+1;i++)
    {
        for(j=0;j<l2+1;j++){
        if (strcmp(S1[i],S2[j])==0)
        {
            for(k=0;k<strlen(S1[i]);k++)
                S[m][k]=S1[i][k];
            m++;
        }}
    }
    char SS[max][max];
    int n=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<l3+1;j++)
        {
            if(strcmp(S[i],S3[j])==0)
            {
                for(k=0;k<strlen(S[i]);k++)
                    SS[n][k]=S[i][k];
                n++;
            }
        }
    }
    m=0;
    for(i=0;i<n;i++)
    {
        if(m<=strlen(SS[i+1]))
        m=strlen(SS[i]);
    }
    int h=0;
    for(i=0;i<n;i++)
    {
        if(strlen(SS[i])==m)
        {
        for(j=0;j<m;j++)
        {
            *(buffer+h)=SS[i][j];
            h++;
        }
        *(buffer+h)=' ';
        h++;
        }
    }
    return m;
}
int main()
{
    char s1[max]="\0",s2[max]="\0",s3[max]="\0",s[max]="\0";
    gets(s1);
    gets(s2);
    gets(s3);
    char*b=s;
    int k=Longest_substring(s1,s2,s3,b);
    if(k==0)
    printf("NULL");
    else
    printf("%s%d",s,k);
}