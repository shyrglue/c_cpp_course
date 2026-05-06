#include<stdio.h>
#include<string.h>
int main()
{
    char dict[1000];
    fgets(dict,1000,stdin);
    
    int i=0,t;
    for(;i<1000;i++)
    {
        if(dict[i]=='e'&&dict[i+1]=='n'&&dict[i+2]=='d')
        {
            dict[i-1]='\n';
            for(t=i;t<1000;t++)
            dict[i]='\0';
            break;
        }
    }
    int num[1000];
    for (i=0;i<1000;i++)
    num[i]=0;
    int j=0;
    for(i=0;i<strlen(dict)-1;i++)
    {
        if (dict[i]!=' '&&dict[i]!='\t')
            num[j]++;
        else
            j++;
    }
    char ans[1000][1000];
    int a,b=0,l;
    for(i=0;i<=j;i++)
    {
        if(dict[i]=='\n'||dict[i]=='\t')
        {
            i--;
            continue;
        }
            l=i;
            for(a=0;a<i;a++)
            {
                l+=num[a];
            }
            for(a=0;a<num[i];a++)
            {
                ans[b][a]=dict[l+a];
            }
            b++;
    }
    
    for(i=0;i<b;i++)
    {
        if(num[i]<0)
        continue;
        else
        {
            num[i]=1;
            for(j=i+1;j<b;j++)
            {
                if(strcmp(ans[i],ans[j])==0)
                {
                    num[i]++;
                    num[j]=-1;
                }
            }
        }
    }
    int m=0;
    for(i=0;i<b;i++)
    {
        if (m<num[i])
        m=num[i];
    }
    for(i=0;i<b;i++)
    {
        if (num[i]==m)
        printf("%s %d\n",ans[i],m);
    }
}