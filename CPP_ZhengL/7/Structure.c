#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu{
    char name[100];
    char no[100];
    char home[100];
    char age[100];
    char gen[100];
}stu[128];

void input()
{
    int n,i,j;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char in[1000]="\0";
        gets(in);
        strcpy(stu[i].name,strtok(in,","));
        strcpy(stu[i].no,strtok(NULL,", "));
        strcpy(stu[i].home,strtok(NULL,", "));
        strcpy(stu[i].age,strtok(NULL,", "));
        strcpy(stu[i].gen,strtok(NULL,", "));
    }
}
void output()
{
    int i;
    for(i=0;i<128;i++)
    {
        printf("%s, %s, %s, %s, %s\n",stu[i].name,stu[i].no,stu[i].home,stu[i].age,stu[i].gen);
        if(stu[i+1].name[0]=='\0') break;
    }
}
void search()
{
    char s[100]="\0";
    int j,i,num,n,c=0;
    while(gets(s)&&strcmp(s,"quit"))
    {
        c=0;
        for(i=0;i<100;i++)
        {
            if(s[i]==',') c++;
        }
        char search[5][100]={"\0","\0","\0","\0","\0"};
    
        strcpy(search[0],strtok(s,",\n"));
        for(i=1;i<c+1;i++)
        strcpy(search[i],strtok(NULL,","));
        int f,ff=0,ii;
        for(i=0;i<128;i++)
        {
            f=0;
            for(j=0;j<=c;j++)
            {
                if(strcmp(search[j],stu[i].name)==0||strcmp(search[j],stu[i].no)==0||strcmp(search[j],stu[i].home)==0||strcmp(search[j],stu[i].age)==0||strcmp(search[j],stu[i].gen)==0)
                f++;
            }
            if(f==c+1)
            {
                ff++;
                ii=i;
            }
            if(stu[i+1].name[0]=='\0') break;
        }
        if(ff==1)
            printf("%s, %s, %s, %s, %s\n",stu[ii].name,stu[ii].no,stu[ii].home,stu[ii].age,stu[ii].gen);
        else printf("error\n");
        for(i=0;i<100;i++)
        s[i]='\0';
    }
}
int main()
{
    input();
    output();
    search();
}