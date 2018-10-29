#include<iostream>
using namespace std;
int main()
{
	cout<<"1.Encryption\n2.Decryption:\n";
	int k,i,e;
	cin>>e;
	string p;
	if(e==1)
	{
	cout<<"enter plain text:";
	cin>>p;
	cout<<"Enter key:";
	cin>>k;
	char cipher[20]={'\0'};
	cout<<"Cipher text:";
	for(i=0;i<=sizeof(p);i++)
	{
		cipher[i]=char((int(p[i])+k)%(26+97));
		cout<<cipher[i];
	}
    }
    else if(e==2)
    {
    cout<<"enter cipher text:";
	cin>>p;
	cout<<"Enter key:";
	cin>>k;
	char cipher[20]={'\0'};
	cout<<"Plain text:";
	for(i=0;i<=sizeof(p);i++)
	{
		cipher[i]=char((int(p[i])-k)%(26+97));
		cout<<cipher[i];
	}
	}
	return 0;
}
