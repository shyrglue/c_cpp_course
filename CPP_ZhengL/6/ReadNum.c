#include<stdio.h>
#include<string.h>
void one(int a,char r[])
{
    if(a==1) strcpy(r,"ONE");
    else if(a==2) strcpy(r,"TWO");
    else if(a==3) strcpy(r,"THREE");
    else if(a==4) strcpy(r,"FOUR");
    else if(a==5) strcpy(r,"FIVE");
    else if(a==6) strcpy(r,"SIX");
    else if(a==7) strcpy(r,"SEVEN");
    else if(a==8) strcpy(r,"EIGHT");
    else if(a==9) strcpy(r,"NINE");
}
void t(int a,char r[],const char b[])
{
    one(a%10,r);
    r[strlen(b)]=' ';
    for(int i=strlen(r)+strlen(b);i>strlen(b);i--)
    r[i]=r[i-strlen(b)-1];
    for(int i=0;i<strlen(b);i++)
    r[i]=b[i];
}
void two(int a,char r[])
{
    if(a<10) one(a,r);
    else if(a==10) strcpy(r,"TEN");
    else if(a==11) strcpy(r,"ELEVEN");
    else if(a==12) strcpy(r,"TWELVE");
    else if(a==13) strcpy(r,"THIRTEEN");
    else if(a==14) strcpy(r,"FOURTEEN");
    else if(a==15) strcpy(r,"FIFTEEN");
    else if(a==16) strcpy(r,"SIXTEEN");
    else if(a==17) strcpy(r,"SEVENTEEN");
    else if(a==18) strcpy(r,"EIGHTEEN");
    else if(a==19) strcpy(r,"NINETEEN");
    else if(a/10==2) t(a,r,"FORTY");
    else if(a/10==3) t(a,r,"THIRTY");
    else if(a/10==4) t(a,r,"FORTY");
    else if(a/10==5) t(a,r,"FIFTY");
    else if(a/10==6) t(a,r,"SIXTY");
    else if(a/10==7) t(a,r,"SEVENTY");
    else if(a/10==8) t(a,r,"EIGHTY");
    else if(a/10==9) t(a,r,"NINTY");
}
int int2call(int amount,char *buffer)
{
    char a[100]="\0",b[100]="\0",c[100]="\0";
    two(amount/1000,a);
    one(amount/100%10,b);
    two(amount%100,c);
    if(strlen(a)!=0)
    strcat(a," THOUSAND ");
    if(strlen(b)!=0)
    {
    strcat(b," HUNDRED ");
    strcat(a,b);
    }
    if(strlen(c)!=0)
    strcat(a,c);
    strcpy(buffer,a);
    printf("%s",buffer);
    return(strlen(buffer));
}
int main()
{
    int amount;
    scanf("%d",&amount);
    char buffer[1000]="\0";
    if(amount>0&&amount<65535) int2call(amount,buffer);
    else printf("ERROR");
}