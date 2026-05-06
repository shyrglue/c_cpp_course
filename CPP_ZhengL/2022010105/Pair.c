#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>

typedef struct point{
	int x; int y;
}POINT;

void main()
{
	POINT set[70], temp;
	int cnt, i, j, ymax = 0;
	cnt = 0;
	scanf("%d %d", &i, &j);
	while (i != 0)
	{
		set[cnt].x = i; set[cnt].y = j;
		cnt++;
		scanf("%d %d", &i, &j);
	}
	scanf("%d %d", &i, &j);
	while (i != 0)
	{
		set[cnt].x = i; set[cnt].y = j;
		cnt++;
		scanf("%d %d", &i, &j);
	}
	for (i = 0; i <= cnt - 2; i++)
	{
		for (j = 0; j <= cnt - i - 2; j++)
		{
			if (set[j].x > set[j + 1].x)
			{
				temp = set[j];
				set[j] = set[j + 1];
				set[j + 1] = temp;
			}
		}
	}
	for (i = 0; i <= cnt - 1; )
	{
		if (i == cnt - 1)
			break;
		if (set[i].x == set[i + 1].x)
		{
			set[i].y = (set[i].y + set[i + 1].y) / 2 ;
			set[i + 1].x = -1; set[i + 1].y = -100;
			i += 2;
		}
		else
			i++;
	}
	for (i = 0; i <= cnt - 1; i++)
	{
		if (set[i].x != -1)
			printf("%d %d\n", set[i].x, set[i].y);
	}
	for(i = 0; i <= cnt - 1; i++)
		ymax = (ymax >= set[i].y) ? ymax : set[i].y;
	for(i = 0; i <= cnt - 1; i++)
	{
		if(set[i].x == -1)
			continue;
		if (set[i].y == ymax)
			printf("(%d,%d)\n", set[i].x, set[i].y);
	}
}