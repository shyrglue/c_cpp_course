#include<stdio.h>
#include<math.h>
int main()
{
    int money,way;
    double mni;
    mni=0;
    scanf("%d%d",&money,&way);
    if (way==1)
    {
        mni=money*(1+5*0.055);
        printf("%.2lf",mni);
    }
    else if (way==2)
    {
        mni=money*(1+2*0.044)*(1+3*0.05);
        printf("%.2lf",mni);
    }
    else if(way==3)
    {
        mni=money*(1+3*0.05)*(1+2*0.044);
        printf("%.2lf",mni);
    }
    else if(way==4)
    {
        mni=money*pow(1+0.035,5);
        printf("%.2lf",mni);
    }
    else if(way==5)
    {
        mni=money*pow(1+0.005/4,5*4);
        printf("%.2lf",mni);
    }
    printf("%d",money);
}