#include<stdio.h>
#include<string.h>
#include<ctype.h>
int analysis(char *s, int v[])
{
    int i,m;
    if(isdigit(s[strlen(s)-1]))
    {
        if(s[strlen(s)-2]=='+'||strlen(s)==1)
v[0]=s[strlen(s)-1]-'0';
else if(s[strlen(s)-2]=='-')
v[0]=-(s[strlen(s)-1]-'0');
    }
    
    
    for(i=strlen(s);i>=0;i--)
    {
        if((s[i]=='+'||s[i]=='-'||s[i]=='\0')&&s[i-1]=='x')
        {
            m=1;
            if(isdigit(s[i-2]))
            {
                if(s[i-3]=='-') v[m]=0-(s[i-2]-'0');
                else v[m]=s[i-2]-'0';
            }
            else
            v[1]=1;
        }
        if(s[i]=='^')
        {
            m=s[i+1]-'0';
            if(isdigit(s[i-2]))
            {
                if(s[i-3]=='-') v[m]=-(s[i-2]-'0');
                else v[m]=s[i-2]-'0';
            }
            else if(s[i-2]=='-')
            v[m]=-1;
            else if(s[i-2]=='+'||i==1)
            v[m]=1;
        }
    }
    return m;
}

int polycomb(char *s1, char *s2, char *buffer)
{
    int v1[100]={0},v2[100]={0};
    int m=analysis(s1,v1)>analysis(s2,v2)?analysis(s1,v1):analysis(s2,v2);
    

    for(int i=0;i<=m;i++)
    {
        v1[i]+=v2[i];
    }

    for(int i=99;i>0;i--)
    {
        
        if(v1[i]!=0){
            char b[100]="\0";


            if(v1[i]*v1[i]==1){
        if(v1[i]==1)
            b[0]='+'; 
        else if(v1[i]==-1)
            b[0]='-';
            b[1]='x';
if(i>1)
            {
            b[2]='^';
            b[3]=i+'0';
            }
            
            }

else {
        if(v1[i]>1) {b[0]='+';
        b[1]=v1[i]+'0';
        }
        else if(v1[i]<-1)
        {b[0]='-';       
            b[1]=-v1[i]+'0';}
            b[2]='x';
            if(i>1)
            {
            b[3]='^';
            b[4]=i+'0';
            }
}

        strcat(buffer,b);
        }
            
            }

            char b[100]="\0";
            if(v1[0]>0)
            {
                b[0]='+';
                b[1]=v1[0]+'0';
            }
            else if (v1[0]<0)
            {
                b[0]='-';
                b[1]=-v1[0]+'0';
            }
            strcat(buffer,b);
            if(buffer[0]=='+')
            for(int i=0;i<strlen(buffer);i++)
            buffer[i]=buffer[i+1];
            

            
            
int i;
    for(i=99;i>=0;i--){
        if(v1[i]!=0)
           break;}
return v1[i];
}




int main()
{
    char a[100],b[100],buf[100]="\0";
    gets(a);
    gets(b);
    int t=polycomb(a,b,buf);

    printf("%s %d",buf,t);
}