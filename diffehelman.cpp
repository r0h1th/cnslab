#include<iostream>
#include<math.h>
using namespace std;
int keygen(int g,int a,int n)
{ int A=1,i;
	   for(i=1;i<=a;i++)
	      {
	      	A=(A*g)%n;
	      	//cout<<A<<"\n";
		  }
		  return A;
}
int findg(int n)
{ 
	int i,j,k,l=0,prim[n],check[n],flag=0,ind;
	cout<<"The primitive roots are:\n";
	for(i=2;i<n;i++)
	{  for(j=1;j<n;j++) check[j]=0; flag=0;
		for(j=1;j<n;j++)
		{ 
			check[j]=keygen(i,j,n);
			for(k=1;k<j;k++)
			{
			    if(check[j]==check[k])
			      {
				  flag=1; break;}
		    }
		    if(flag==1) break;
		}
		if(flag==0)
		{ 
			prim[l++]=i;
			//cout<<l-1<<" "<<i<<"\n";
		}
	}
		cout<<"choose primitive root index:";
		cin>>ind;
		cout<<"choosen primitive root="<<prim[ind];
  return prim[ind];
}

int main()
{
	int A,B,a,b,n,g;
	cout<<"enter prime number n:";cin>>n;
	g=findg(n);
    cout<<"\nenter a(private key of A) and b(private key of B):";
    cin>>a>>b;
    A=keygen(g,a,n);
    B=keygen(g,b,n);
    cout<<"Private keys: A="<<A<<" B="<<B<<endl;
    cout<<"Secret keys for A="<<keygen(A,b,n)<<" and for B="<<keygen(B,a,n)<<endl;
}
