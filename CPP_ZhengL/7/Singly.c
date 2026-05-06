#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu
{
	long no;
	char name[21];
	struct stu *next;
}*STU;
void swapchar(char *s1, char *s2)
{
	char t[21];
	strcpy(t, s1); 
    strcpy(s1, s2); 
    strcpy(s2, t);
}
void swapint(long *a, long *b)
{
	long t;
	t = *a;
    *a = *b;
    *b = t;
}
int main()
{
	STU h, p1, p2;
	char *a,t[52];
	int N, z;
	h = (STU)malloc(sizeof(struct stu)); h->next = NULL;
	gets(t);
	while ((a = strchr(t, ',')) != NULL)
	{
		*a = '\0'; a += 2;
		p2 = (STU)malloc(sizeof(struct stu));
		if (h->next == NULL)h->next = p2;
		else	p1->next = p2;
		p1 = p2;
		p2->next = NULL;
		p1->no = atol(t);
		strcpy(p1->name, a);
		gets(t);
	}
	for (p1 = h->next; p1->next != NULL; p1 = p1->next)
	{
		for (p2 = p1; p2 != NULL; p2 = p2->next)
		{
			if (p2->no > p1->no)
			{
				swapint(&(p2->no), &(p1->no));
				swapchar(p2->name, p1->name);
			}
		}
	}
	p1 = h->next; N = 0;
	while (p1 != NULL)
	{
		N++;
		p1 = p1->next;
	}
	printf("%d\n", N);
	for (p1 = h->next; p1 != NULL; p1 = p1->next)printf("%ld, %s\n", p1->no, p1->name);
	for (p1 = h, z = 0; p1->next != NULL; p1 = p1->next)
	{
		if (atol(t) == p1->next->no)
		{
			z = 1;
			break;
		}
	}
	if (!(z))printf("ERROR");
	else
	{
		if (p1->next->next != NULL)printf("%ld, %s\n", p1->next->next->no, p1->next->next->name);
		if (p1 != h)printf("%ld, %s\n", p1->no, p1->name);
	}
	for (p1 = h->next; p1 != NULL; p1 = p1->next)
	{
		free(h);
		h = p1;
	}
	free(h);
}