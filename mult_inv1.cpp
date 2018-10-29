#include <stdio.h>
#include<iostream>
using namespace std;
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
     if (m == 1)
      return 0;
 
    while (a > 1)
    {
        int q = a / m;
        int t = m; 
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0; 
    return x;
}
 
// Driver program to test above function
int main()
{
    int a,n;
    cout<<"enter no.s:";
    cin>>a>>n;
    cout<<"Modular multiplicative inverse is "<<modInverse(a, n);
    return 0;
}
