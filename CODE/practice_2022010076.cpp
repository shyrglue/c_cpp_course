#include<iostream>
using namespace std;

void sample(int n, int r, bool ordered, bool replacement)
{
    cout<<"  ";
    for(size_t i=0; i<r; i++)
    {
        cout<<" X"<<r;
    }
    if(ordered&&replacement)
    {
        for(size_t i=0; i<n; i++)
        {
            int k=1;
            for(size_t j=0; j<n; j++)
            {
                cout<<" "<<k<<"  "<<j<<"  "<<i
            }
        }
    }
}
int main()
{

}