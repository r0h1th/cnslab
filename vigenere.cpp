#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string p,k;
	char key[26][26],ch='a';
	int i,j,n=26,m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			key[i][j]=ch;
			ch++;
			if(ch=='{')
			ch='a';   
		}
		ch++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<key[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"Enter plain text:";
	cin>>p;
	cout<<"Enter key:";
	cin>>k;
	cout<<"Cipher text:\n";
    for(i=0,j=0;p[i]!='\0';i++,j++)
    {
    		cout<<p[i]<<" "<<k[j]<<"\n";
    		m=((int)p[i]-97)%(26);
    		n=((int)k[j]-97)%(26);
    		cout<<m<<" "<<n<<"\n";
    		ch=char(key[m][n]);
    		cout<<ch<<"\n";
    		if(k[j+1]=='\0')
	        	j=-1;
	}
	
}
