#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>
typedef struct seg{
	int num;
	int vec;
	struct seg *next;
}*SEG;

void intcha(int *a, int *b){
	int temp;
	temp = *a; *a = *b; *b = temp;}

void creatLIST(SEG head, int N)
{
	int i;
	SEG pre, cur;
	for(i = 1; i <= N; i++)
	{
		cur = (SEG)malloc(sizeof(struct seg));
		scanf("%d %d", &(cur->num), &(cur->vec));
		if (head->next == NULL)
			head->next = cur;
		else
			pre->next = cur;
		pre = cur; cur->next = NULL;
	}
}

void outputLIST(SEG head)
{
	SEG pt;
	for (pt = head->next; pt != NULL; pt = pt->next)
		printf("%d %d\n", pt->num, pt->vec);
}

void deleteLIST(SEG head)
{
	SEG pt;
	for (pt = head->next; pt != NULL; pt = pt->next)
	{
		free(head);
		head = pt;
	}
	free(head);
}


void main()
{
	int n1, n2, N;
	SEG head1, head2, pt1, pt2;
	head1 = (SEG)malloc(sizeof(struct seg));
	head1->next = NULL;
	head2 = (SEG)malloc(sizeof(struct seg));
	head2->next = NULL;
	scanf("%d", &n1); creatLIST(head1, n1);
	scanf("%d", &n2); creatLIST(head2, n2);
	pt1 = head1;
	while (pt1->next != NULL)
		pt1 = pt1->next;
	pt1->next = head2->next; free(head2); head2 = NULL;
	for (pt1 = head1->next; pt1->next != NULL; pt1 = pt1->next)
	{
		for (pt2 = pt1; pt2 != NULL; pt2 = pt2->next)
		{
			if (pt2->vec < pt1->vec)
			{
				intcha(&(pt2->vec), &(pt1->vec)); intcha(&(pt2->num), &(pt1->num));
			}
		}
	}
	for (pt1 = head1->next; pt1 != NULL; pt1 = pt1->next)
	{
		if (pt1->next == NULL)
			continue;
		if (pt1->vec != pt1->next->vec)
			continue;
		pt1->num += pt1->next->num;
		pt1->next->vec = -1;
		pt1 = pt1->next;
	}
	for (pt1 = head1; pt1->next != NULL; )
	{
		if(pt1->next->vec == -1 or pt1->next->num == 0)
		{
			pt2 = pt1->next;
			pt1->next = pt2->next;
			free(pt2); pt2 = NULL;
			continue;
		}
		pt1 = pt1->next;
	}
	pt1 = head1->next; N = 0;
	while (pt1 != NULL)
	{
		N++; pt1 = pt1->next;}
	printf("%d\n", N);
	outputLIST(head1);
	deleteLIST(head1);
}