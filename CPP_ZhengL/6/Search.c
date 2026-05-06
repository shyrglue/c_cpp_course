#include<stdio.h>
#include<string.h>

int main()
{
    char dict[17][20]={
        "C",
        "C++",
        "Python",
        "Java",
        "Basic",
        "C#",
        "PHP",
        "Javascript",
        "SQL",
        "Ruby",
        "Matlab",
        "Go",
        "Perl",
        "R",
        "Fortran",
        "Pascal",
        "Swift"
    };
    char input[20]="\0";
    scanf("%s",input);
    int i,j,t,k,n[17]={0};
    for(i=0;i<17;i++)
    {
        for(k=0;k<=strlen(dict[i]);k++)
        {
            t=0;
            for(j=0;j<strlen(input);j++)
            {
                if(input[j]==dict[i][k+j])
                t++;
            }
            if(t==strlen(input))
            {
                n[i]=1;
                break;
            }
        }
        
    }
    for(i=0;i<17;i++)
    {
        if(n[i]!=0)
        printf("%s\n",dict[i]);
    }
}