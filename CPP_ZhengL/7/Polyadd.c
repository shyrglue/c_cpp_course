#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct x{
	int num;
	int ex;
	struct x *next;
}*X;



void newl(X s, int N)
{
	int i;
	X prev, curr;
	for(i = 1; i <= N; i++)
	{
		curr = (X)malloc(sizeof(struct x));
		scanf("%d %d", &(curr->num), &(curr->ex));
		if (s->next == NULL)	s->next = curr;
		else	prev->next = curr;
		prev = curr;
		curr->next = NULL;
	}
}

void output(X s)
{
	X p;
	for (p = s->next; p != NULL; p = p->next)	printf("%d %d\n", p->num, p->ex);
}

void del(X s)
{
	X p;
	for (p = s->next; p != NULL; p = p->next)
	{
		free(s);
		s = p;
	}
	free(s);
}
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int n1, n2, N;
	X s1, s2, p1, p2;
	s1 = (X)malloc(sizeof(struct x));
	s1->next = NULL;
	s2 = (X)malloc(sizeof(struct x));
	s2->next = NULL;
	scanf("%d", &n1); newl(s1, n1);
	scanf("%d", &n2); newl(s2, n2);
	p1 = s1;
	while (p1->next != NULL)	p1 = p1->next;
	p1->next = s2->next; free(s2);
	s2 = NULL;
	for (p1 = s1->next; p1->next != NULL; p1 = p1->next)
	{
		for (p2 = p1; p2 != NULL; p2 = p2->next)
		{
			if (p2->ex < p1->ex)
			{
				swap(&(p2->ex), &(p1->ex)); swap(&(p2->num), &(p1->num));
			}
		}
	}
	for (p1 = s1->next; p1 != NULL; p1 = p1->next)
	{
		if (p1->next == NULL)	continue;
		if (p1->ex != p1->next->ex)	continue;
		p1->num += p1->next->num;
		p1->next->ex = -1;
		p1 = p1->next;
	}
	for (p1 = s1; p1->next != NULL; )
	{
		if(p1->next->ex == -1 || p1->next->num == 0)
		{
			p2 = p1->next;
			p1->next = p2->next;
			free(p2);
			p2 = NULL;
			continue;
		}
		p1 = p1->next;
	}
	p1 = s1->next;
	N = 0;
	while (p1 != NULL)
	{
		N++;
		p1 = p1->next;
	}
	printf("%d\n", N);
	output(s1);
	del(s1);
}