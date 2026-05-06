#include<stdio.h>

struct date{
    int y;
    int m;
    int d;
}f,l,t;

void s()
{
    t=f;
    f=l;
    l=t;
}
int leap(int y)
{
    if(y%400==0||(y%4==0&&y%100!=0)) return 1;
    return 0;
}
int main()
{
    scanf("%d%d%d%d%d%d",&f.y,&f.m,&f.d,&l.y,&l.m,&l.d);
    if(f.y>l.y) s();
    else if(f.y==l.y)
    {
        if(f.m>l.m) s();
        else if(f.m==l.m)
            if(f.d>l.d) s();
    }

    int num[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    if(f.y==l.y)
    {
        int d;
        if(f.m==l.m) printf("%d",l.d-f.d);
        else
        {
            d=l.d-f.d;
            if(leap(f.y)) num[1]++;
            for(i=f.m;i<l.m;i++)
                d+=num[i-1];
            printf("%d",d);
        }
    }
    else
    {
        int d=0;
        for(i=f.y;i<l.y;i++)
            if(leap(i)) d++;
        d+=365*(l.y-f.y);

        for(i=1;i<f.m;i++) d-=num[i-1];
        if(leap(l.y)) num[1]++;
        for(i=1;i<l.m;i++) d+=num[i-1];
        d+=l.d-f.d;
        printf("%d",d);
    }
}