#include<stdio.h>
int fun(int arr[],int t)
{int i,sum=0;
 for(i=0;i<t;i++)
 sum+=arr[i]; 
 return sum;
}
int main()
{int a[1000],n,i,sum;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 sum=fun(a,n);
 printf("%d",sum);
 return 0;
}