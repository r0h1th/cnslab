#include <iostream>
using namespace std;
int main()
{
	int a,n;
	cout<<"enter no. to find multiplicative inverse, in range:";
	cin>>a>>n;
	cout<<"The multiplicative inverse of "<<a<<" is ";
	for(int i=0;i<n;i++)
	{
		if((a*i)%n==1){
		    cout<<i;break;}
	}
	return 0;
}
