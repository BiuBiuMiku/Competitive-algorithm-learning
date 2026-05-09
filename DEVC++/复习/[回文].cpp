#include<bits/stdc++.h>
using namespace std;
const int oo=2005;
string str;
int f[1005][1005];
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++)
		for(int j=0;j<str.size();j++)
			f[i][j]=oo;	
	for(int i=0;i<str.size();i++)f[i][i]=0;
	for(int i=0;i<str.size()-1;i++){
		if(str[i]==str[i+1])f[i][i+1]=0;
		else f[i][i+1]=1;
	}
	for(int len=2;len<str.size();len++){
		for(int i=0;i<str.size()-len;i++){
			int j=i+len;
			if(str[i]==str[j])f[i][j]=f[i+1][j-1];
			else f[i][j]=min(f[i+1][j]+1,min(f[i][j-1]+1,f[i][j])); 
		}
	}
	printf("%d",f[0][str.size()-1]);
	return 0;
}

