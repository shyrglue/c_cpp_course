#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>

typedef struct stu{
	int num;
	struct stu *next;
}NODE, *LINK;


void main()
{
	int m, n, i, j;
	LINK fo, la, st;
	scanf("%d %d", &n, &m);
	if (m == 1)
		printf("%d", n);
	else
	{
		fo = (LINK)malloc(sizeof(NODE));
		fo->num = 1; st = fo;
		for (i = 2; i <= n; i++)
		{
			la = (LINK)malloc(sizeof(NODE));
			la->num = i;
			fo->next = la;
			fo = la; la = NULL;
		}
		fo->next = st;
		fo = NULL; la = NULL;
		for (i = n; i >= 2; i--)
		{
			for (j = 1; j <= m - 2; j++)
				st = st->next;
			fo = st->next;
			st->next = fo->next;
			st = st->next;
			free(fo); fo = NULL;
		}
		printf("%d", st->num);
		free(st);
	}
}