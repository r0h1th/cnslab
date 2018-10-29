#include<iostream>
using namespace std;
int main()
{
	string p,k;
	//cout<<"enter plain text:";
	//cin>>p;
	cout<<"enter key:";
	cin>>k;
	char key[5][5],ch='a';
	int n=5,i,j,l=0;
	char arr[26]={'x'};
	arr[0]=k[0];
	for(i=0;i<26;i++)
	{ 
		for(j=0;j<i;j++)
		{
		 if(l<sizeof(k))
		 { if(arr[j]==k[l++])
		    i--;
		    else
  		   arr[i]=k[l++];
  	    }
  	    else
  	    { 
		  if(arr[j]==ch)
		    ch++;
		    else
  		   arr[i]=ch++;
  	    }
	    }
    }
	l=0;
	for(i=0;i<n;i++)
	 { for(j=0;j<n;j++)
	  {
	  	key[i][j]=arr[l++];
	  	cout<<key[i][j]<<" ";
	  }cout<<"\n";
    }
	return 0;
}
