#include<iostream>
#include <string>
#include<stdlib.h>
using namespace std;
int search(int a,int* arr)
{
	for(int i=0;i<64;i++)
	if(a==arr[i])
	   return i;
}
int main()
{
	int initial[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
	                 57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7},
	      final[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
		  36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25},
		  parity_drop_key={ };
	string s,key;int n,i,r,j; 
	cout<<"enter input: ";
	cin>>s;    
	cout<<"enter key:";
	cin>>key;
	int p[64]={0};
	for(i=0;i<8;i++)
	{
		j=8*(i+1);
		n=int(s[i]);
		while(n!=0) {r=(n%2==0 ? 0 : 1); n/=2; p[--j]=r;  // cout<<plain[j];
		}
		//cout<<"\n";
	}
	for(i=0;i<64;i++){cout<<p[i];}
	cout<<endl;
    int f1[64]={0};
    cout<<"after initial permutation:\n";
	for(i=0;i<64;i++){
    	if(p[i]==1)
    	{
    		f1[search(i+1,initial)]=1;
		}
		
	}
	for(i=0;i<64;i++)
	cout<<f1[i];
	//cipher=g.to_string();
	//cout<<cipher;
	/*for(int i=0;i<64;i++){
    	cout<<g[i];
	 bitstream<64> text(n)=;int j=0;
	 for(int i = 0; i < s.size(); ++i)
	     text[j++]= bitset<8>(s.c_str()[i]);
	     
	 //	 cout << bitset<8>(s.c_str()[i]) << endl;*/
int kp[64]={0};
for(i=0;i<8;i++)
	{
		j=8*(i+1);
		n=int(key[i]);
		while(n!=0) {r=(n%2==0 ? 0 : 1); n/=2; kp[--j]=r;  // cout<<plain[j];
		}
		//cout<<"\n";
	}


}
