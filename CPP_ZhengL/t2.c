#include<stdio.h>
main()
{
 char u[21];
 gets(u);
 char temp;
 int i, j, k;
 for(i=0;i<20;i++)
  for (j = 0;j < 20 - i;j++) {
   if (u[j] > u[j + 1]) {
    temp = u[j];
    u[j] = u[j + 1];
    u[j + 1] = temp;
   }
  }
 for (k = 0;k < 20;k++) 
 {
  printf("%c", u[k]);
 }
 printf("\n");
 return 0;
}