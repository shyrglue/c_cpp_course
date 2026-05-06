#include <stdio.h>

struct pair
{
	int x;
    int y;
};

int main()
{
	struct pair p[100],t;
	int n=0,i,j,m=0,y=0;
	while (1)
	{
        scanf("%d %d", &i, &j);
        if(i==0)
        {
            if(m==1)
            break;
            else{
            m=1;
            continue;}
        }
		p[n].x = i;
        p[n].y = j;
		n++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].x>p[j+1].x)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(p[i].x==p[i+1].x)
		{
            p[i].y=(p[i].y+p[i+1].y)/2;
            p[i+1].x=-1;
            p[i+1].y=-1;
			i++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(p[i].x != -1)
			printf("%d %d\n",p[i].x,p[i].y);
	}
	for(i=0;i<n;i++) 
    if(y<p[i].y) y=p[i].y;
	for(i=0;i<n;i++)
	{
		if(p[i].x==-1) continue;
		if(p[i].y==y)
			printf("(%d,%d)\n",p[i].x,p[i].y);
	}
}