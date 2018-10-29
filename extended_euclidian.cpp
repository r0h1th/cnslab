#include <iostream>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
     int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 printf("%d %d %d %d \n",*x,*y,x1,y1);
    return gcd;
}
 
int main()
{
    int a,b,x,y;
	cout<<"enter 2 no.s:";
	cin>>a>>b;
    int g = gcdExtended(a, b, &x, &y);
    printf("gcd(%d, %d) = %d", a, b, g);
    return 0;
}
