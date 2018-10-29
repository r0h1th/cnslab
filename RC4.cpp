#include<iostream>
using namespace std;
int main()
{
	string p,key;
	int s[256],k[256],n=256,ind=0,i,j,t;
	cout<<"enter plaintext:";
	cin>>p;
	cout<<"enter key:";
	cin>>key;
	
	for(i=0;i<n;i++)
	{
		s[i]=i;
		k[i]=(int)key[ind++];
		if(ind==key.length())
		    ind=0;
		//cout<<k[i];
	}
	j=0;
	for(i=0;i<n;i++)
	{
		j=(j+s[i]+k[i]) % n;
		s[i]=s[i]^s[j];
		s[j]=s[i]^s[j];
		s[i]=s[i]^s[j];
	}
	cout<<"\nSbox after permutation:";
	for(i=0;i<n;i++)
	    cout<<s[i]<<" ";
	
	i=j=0;
	int cnt=0;
	int cip[p.length()],pln[p.length()];
	
	while(cnt!=p.length())
	{
		i=(i+1)%n;
		j=(j+s[i])%n;
		cout<<j<<" ";
		s[i]=s[i]^s[j];
		s[j]=s[i]^s[j];
		s[i]=s[i]^s[j];
		t=(s[i]+s[j])%n;
		cip[cnt]=(s[t]^p[cnt]);
		pln[cnt]=(s[t]^cip[cnt]);
		cnt++;
	}	
	cout<<"\n encrypted message:";
	for(i=0;i<p.length();i++)
	cout<<(char)cip[i]<<" ";
	cout<<"\n decrypted message:";
	for(i=0;i<p.length();i++)
	cout<<(char)pln[i]<<" ";
}
