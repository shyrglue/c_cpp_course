#include<stdio.h>
//结构体-简单明了且好用
typedef struct book
{
    char title[100];
    char author[100];
}book;

int main()
{

    book books[10];
    gets(books[0].title);
    gets(books[0].author);

    book *b=&books[0];

    printf("%s %s",(*b).title,b->author);
    //指针引用...
}