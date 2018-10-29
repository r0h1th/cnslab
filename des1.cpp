#include<iostream>
#include<cstring>
using namespace std;

int init[8][8]={

{58,50,42,34,26,18,10,2},{60,52,44,36,28,20,12,4},{62,54,46,38,30,22,14,6},{64,56,48,40,32,24,16,8},{57,49,41,33,25,17,9,1},{59,51,43,35,27,19,11,3},{61,53,45,37,29,21,13,5},{63,55,47,39,31,23,15,7}

};



int final[8][8]={
	{40,8,48,16,56,24,64,32},{39,7,47,15,55,23,63,31},{38,6,46,14,54,22,62,30},{37,5,45,13,53,21,61,29},{36,4,44,12,52,20,60,28},{35,3,43,11,51,19,59,27},{34,2,42,10,50,18,58,26},{33,1,41,9,49,17,57,25}};



void tobin(char c,char *bin,int k){
	
	switch(c){
		case '0':
			bin[k]='0';
			bin[k+1]='0';
			bin[k+2]='0';
			bin[k+3]='0';
			break;
		case '1':
			bin[k]='0';
			bin[k+1]='0';
			bin[k+2]='0';
			bin[k+3]='1';
			
			break;
		case '2':
			bin[k]='0';
			bin[k+1]='0';
			bin[k+2]='1';
			bin[k+3]='0';
			
			break;
		case '3':
			bin[k]='0';
			bin[k+1]='0';
			bin[k+2]='1';
			bin[k+3]='1';
			
			break;
		case '4':
			bin[k]='0';
			bin[k+1]='1';
			bin[k+2]='0';
			bin[k+3]='0';
			
			break;
		case '5':
			bin[k]='0';
			bin[k+1]='1';
			bin[k+2]='0';
			bin[k+3]='1';
			
			break;
		case '6':
			bin[k]='0';
			bin[k+1]='1';
			bin[k+2]='1';
			bin[k+3]='0';
			
			break;
		case '7':
			bin[k]='0';
			bin[k+1]='1';
			bin[k+2]='1';
			bin[k+3]='1';
			
			break;
		case '8':
			bin[k]='1';
			bin[k+1]='0';
			bin[k+2]='0';
			bin[k+3]='0';
			
			break;
		case '9':
			bin[k]='1';
			bin[k+1]='0';
			bin[k+2]='0';
			bin[k+3]='1';
			
			break;
		case 'A':
			bin[k]='1';
			bin[k+1]='0';
			bin[k+2]='1';
			bin[k+3]='0';
			
			break;
		case 'B':
			bin[k]='1';
			bin[k+1]='0';
			bin[k+2]='1';
			bin[k+3]='1';
			
			break;
		case 'C':
			bin[k]='1';
			bin[k+1]='1';
			bin[k+2]='0';
			bin[k+3]='0';
			
			break;
		
		case 'D':
			bin[k]='1';
			bin[k+1]='1';
			bin[k+2]='0';
			bin[k+3]='1';
			
			break;
		case 'E':
			bin[k]='1';
			bin[k+1]='1';
			bin[k+2]='1';
			bin[k+3]='0';
			
			break;
		case 'F':
			bin[k]='1';
			bin[k+1]='1';
			bin[k+2]='1';
			bin[k+3]='1';
			
			break;
		
	}
	bin[k+4]='\0';
	
}

void convert(char pt[100],char bin[100]){
	int k=0;
	for(int i=0;i<strlen(pt);i++){
		tobin(pt[i],bin,k);
		k=k+4;
	}
}

int getpos(int init[8][8],int x){
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	if(init[i][j]==x)
	return i*8+j+1;	
}



void prep(char ct[100],int len){
	for(int i=0;i<len;i++)
	ct[i]='0';
	ct[len]='\0';
}

void encrypt(char pt[100],char ct[100],char bin[100]){
	convert(pt,bin);
	cout<<"binpt:"<<bin<<endl;
	prep(ct,strlen(bin));
	for(int i=0;i<strlen(bin);i++){
		if(bin[i]=='1'){
			int k=getpos(init,i+1);
			cout<<"in encrypt "<<i<<" "<<k<<endl;
			ct[k-1]='1';
		}
	}	
	
}

char tohex(char binct[100],int i){
	if(binct[i]=='0'&&binct[i+1]=='0'&&binct[i+2]=='0'&&binct[i+3]=='0') return '0';
	if(binct[i]=='0'&&binct[i+1]=='0'&&binct[i+2]=='0'&&binct[i+3]=='1') return '1';
	if(binct[i]=='0'&&binct[i+1]=='0'&&binct[i+2]=='1'&&binct[i+3]=='0') return '2';
	if(binct[i]=='0'&&binct[i+1]=='1'&&binct[i+2]=='0'&&binct[i+3]=='1') return '3';
	if(binct[i]=='0'&&binct[i+1]=='1'&&binct[i+2]=='0'&&binct[i+3]=='0') return '4';
	if(binct[i]=='0'&&binct[i+1]=='1'&&binct[i+2]=='0'&&binct[i+3]=='1') return '5';
	if(binct[i]=='0'&&binct[i+1]=='1'&&binct[i+2]=='1'&&binct[i+3]=='0') return '6';
	if(binct[i]=='0'&&binct[i+1]=='1'&&binct[i+2]=='1'&&binct[i+3]=='1') return '7';
	if(binct[i]=='1'&&binct[i+1]=='0'&&binct[i+2]=='0'&&binct[i+3]=='0') return '8';
	if(binct[i]=='1'&&binct[i+1]=='0'&&binct[i+2]=='0'&&binct[i+3]=='1') return '9';
	if(binct[i]=='1'&&binct[i+1]=='0'&&binct[i+2]=='1'&&binct[i+3]=='0') return 'A';
	if(binct[i]=='1'&&binct[i+1]=='0'&&binct[i+2]=='1'&&binct[i+3]=='1') return 'B';
	if(binct[i]=='1'&&binct[i+1]=='1'&&binct[i+2]=='0'&&binct[i+3]=='0') return 'C';
	if(binct[i]=='1'&&binct[i+1]=='1'&&binct[i+2]=='0'&&binct[i+3]=='1') return 'D';
	if(binct[i]=='1'&&binct[i+1]=='1'&&binct[i+2]=='1'&&binct[i+3]=='0') return 'E';
	if(binct[i]=='1'&&binct[i+1]=='1'&&binct[i+2]=='1'&&binct[i+3]=='1') return 'F';
	
}

void bin_hex(char binct[100],char ct[100]){
	
	int k=0;
	for(int i=0;i<strlen(binct);i+=4){
		ct[k++]=tohex(binct,i);
	}
	ct[k]='\0';
	
	
	
}

void decrypt(char binct[100],char binpt[100]){
	for(int i=0;i<strlen(binct);i++){
		if(binct[i]=='1'){
		
		int k=getpos(final,i+1);
		binpt[k-1]='1';
	}
	}
}

void clear(char pt[100]){
	for(int i=0;i<strlen(pt);i++)
	pt[i]='0';
}


int main(){
	
	char pt[100];
	char ct[100];
	char bin[100];
	char binct[100];	
	char binpt[100];

	
	cout<<"Enter pt:"<<endl;
	cin>>pt;
	cout<<"encryption:"<<endl;
	encrypt(pt,binct,binpt);
	cout<<"binary ct:"<<binct<<endl;
	bin_hex(binct,ct);
	cout<<"hex ct:"<<ct<<endl;
	clear(pt);
	clear(binpt);
	decrypt(binct,binpt);
	bin_hex(binpt,pt);
	cout<<"decrypt:"<<endl;
	cout<<"binpt:"<<binpt<<endl;
	cout<<"hexpt:"<<pt<<endl;
	
}
