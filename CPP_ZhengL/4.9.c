#include<stdio.h>
void fun(int arr[],int t)
{int i,j,temp;
 for(i=0;i<t-1-j;i++)
 {if(arr[i]>arr[i+1])
  {temp=arr[i];
   arr[i]=arr[i+1];
   arr[i+1]=temp;
  }
 }
}
int main()
{int n,a[1000],i;
 scanf("%d",&n);
  for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 fun(a,n);
 for(i=0;i<n;i++)
 printf("%d ",a[i]);
 return 0;
}