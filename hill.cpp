#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k[2][2];
	cout<<"Enter the key"<<endl;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	cin>>k[i][j];
	char x,y;
	char a[100],b[100];
	cout<<"Enter the Message"<<endl;
	cin>>a;
	cout<<"encrypted message:";
	int j=0;
	for(int i=0;i<strlen(a);)
	{
//cout<<(int)a[i]-65;
//cout<<(int)a[i+1]-65;

		x=(char)((((int)a[i]-65)*k[0][0]+((int)a[i+1]-65)*k[0][1])%26)+65;
		y=(char)((((int)a[i]-65)*k[1][0]+((int)a[i+1]-65)*k[1][1])%26)+65;
	i=i+2;
		cout<<x<<y;
		b[j++]=x;
		b[j++]=y;
	}
	
}
