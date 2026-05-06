#include<stdio.h>
#include<string.h>
int max(char dict[1000])
{
    int i=0;
    int num[1000];
    for (;i<1000;i++)
    num[i]=0;
    int j=0;
    for(i=0;i<strlen(dict)-1;i++)
    {
        if (dict[i]!=' '&&dict[i]!=','&&dict[i]!='.')
            num[j]++;
        else
            j++;
    }
    int m=0;
    for(i=0;i<=j;i++)//j is the number of words
    {
        if(m<num[i])
        m=num[i];//find the longest
    }
    char ans[1000];
    for (i=0;i<1000;i++)
    ans[i]='\0';


    int a,b=0,l;
    for(i=0;i<=j;i++)
    {
        if(num[i]==m)
        {
            l=i;
            for(a=0;a<i;a++)
            {
                l+=num[a];
            }
            for(a=0;a<m;a++)
            {
                ans[a]=dict[l+a];
            }
            break;
        }
    }
    printf("%s",ans);
}
int main()
{
    char dict[1000];
    fgets(dict,1000,stdin);
    max(dict);
}