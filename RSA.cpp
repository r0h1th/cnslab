#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
int main()
{
	double p,q,n,phi,k=2;int e=2,d1;
    cout<<"enter p,q large prime no.s:";
    cin>>p>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    cout<<"n="<<n<<"\nphi="<<phi;
   while (e < phi) 
    { 
        // e must be co-prime to phi and 
        // smaller than phi. 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    } 
    cout<<"e="<<e;
    d1 = (k*phi + 1)/e;
    unsigned int d=d1;
    cout<<"\nd="<<d;
    double msg,cip,pln;
    cout<<"\nenter msg:";cin>>msg;
    cip=fmod(cip*cip,n);
    if(e%2==0)
        e=e/2;
    else
        e=(e+1)/2;
    cip=pow(msg,e);
    //cout<<"\n"<<cip;
    cip=fmod(cip,n);
    cout<<"\nencrypted message:"<<cip;
    pln=pow(cip,d);
    //cout<<"\n"<<pln;
    pln=fmod(pln,n);
    cout<<"\ndecrypted message:"<<pln;
}
