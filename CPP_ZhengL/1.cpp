#include <iostream> 
#include <cmath> 
using namespace std; 
  
int isPrime(int n) 
{ 
    int i; 
    for(i = 2; i <= sqrt(n); i++) 
        if((n % i) == 0) 
            return 0; 
    return 1; 
} 
int main()
{
    int a[10],b[10],i,n=0;
    for(i=0;i<10;i++)
    {
        cin>>b[i];
        if(isPrime(b[i]))
        {
            a[n]=b[i];
            n++;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}