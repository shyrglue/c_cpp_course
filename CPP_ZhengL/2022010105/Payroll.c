#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>

typedef struct em{
	char no[11];
	char name[11];
	int money;
	struct em *next;
}*PEO;
struct em *link(PEO list1, PEO list2);
void sort(PEO list);
void strcha(char *s1, char *s2)
{
	char temp[12];
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
}

void main()
{
	int n1, n2, i;
	PEO list1, list2, pt;
	scanf("%d", &n1);
	list1 = (PEO)malloc((n1 + 1) * sizeof(struct em));
	list1->next = list1 + 1;
	for (i = 1, pt = list1; i <= n1; i++)
	{
		scanf("%s", pt->next->no);
		scanf("%s", pt->next->name);
		scanf("%d", &(pt->next->money));
		if(i != n1)
			pt->next->next = pt->next + 1;
		else
			pt->next->next = NULL;
		pt = pt->next;
	}
	scanf("%d", &n2);
	list2 = (PEO)malloc((n2 + 1) * sizeof(struct em));
	list2->next = list2 + 1;
	for (i = 1, pt = list2; i <= n2; i++)
	{
		scanf("%s", pt->next->no);
		scanf("%s", pt->next->name);
		scanf("%d", &(pt->next->money));
		if(i != n2)
			pt->next->next = pt->next + 1;
		else
			pt->next->next = NULL;
		pt = pt->next;
	}
	list1 = link(list1, list2);
	for (i = 1, pt = list1->next; i <= n1 + n2; i++, pt = pt->next)
		printf("{%s, %s, %d}\n", pt->no, pt->name, pt->money);
	sort(list1);
	putchar('\n');
	for (i = 1, pt = list1->next; i <= n1 + n2; i++, pt = pt->next)
		printf("{%s, %s, %d}\n", pt->no, pt->name, pt->money);
	free(list1); free(list2);
}

struct em *link(PEO list1, PEO list2)
{
	PEO ed, p, q;
	int tint;
	ed = list1;
	while (ed->next != NULL)
		ed = ed->next;
	ed->next = list2->next;
	while (ed->next != NULL)
		ed = ed->next;
	for (p = list1->next; p->next != NULL; p = p->next)
	{
		for(q = p; q != NULL; q = q->next)
		{
			if((strcmp(q->no, p->no) < 0))
			{
				strcha(q->no, p->no);
				strcha(q->name, p->name);
				tint = q->money; q->money = p->money; p->money = tint;
			}
		}
	}
	return list1;
}

void sort(PEO list)
{
	PEO p, q;
	int tint;
	for (p = list->next; p->next != NULL; p = p->next)
	{
		for (q = p; q != NULL; q = q->next)
		{
			if(q->money < p->money)
			{
				strcha(q->no, p->no);
				strcha(q->name, p->name);
				tint = q->money; q->money = p->money; p->money = tint;
			}
		}
	}
}