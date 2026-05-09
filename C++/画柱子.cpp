#include<bits/stdc++.h>
using namespace std;
int m;	
string str[105]; 
char eng[105],check;
int num[105];
int mmax=-1e9,mmin=1e9;
char answer[105][105];
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>str[i];
		int cur=1;
		eng[i]='+';
		if(str[i][0]=='-')cur=-1;
		for(int j=0;j<str[i].size();j++){
			if(str[i][j]=='-')continue;
			if(str[i][j]>='0'&&str[i][j]<='9')num[i]=num[i]*10+(str[i][j]-'0');
			else eng[i]=str[i][j];
		}
		num[i]*=cur;
		mmax=max(mmax,num[i]);
		mmin=min(mmin,num[i]);
	}
	mmin=abs(mmin);
	for(int i=1;i<=m;i++){
		if(num[i]>=0)
			for(int j=1;j<=num[i];j++)answer[mmax-j+1][i]=eng[i];
		else
			for(int j=1;j<=-num[i];j++)answer[mmax+j][i]=eng[i];
	}
	for(int i=1;i<=mmax;i++){
		for(int j=1;j<=m;j++)
			if(answer[i][j]!=check)cout<<answer[i][j];
			else cout<<" ";
		cout<<endl;
	}		
	for(int j=1;j<=m;j++)cout<<"-";
	cout<<endl;
	for(int i=mmax+1;i<=mmax+mmin;i++){
		for(int j=1;j<=m;j++)
			if(answer[i][j]!=check)cout<<answer[i][j];
			else cout<<" ";
		cout<<endl;
	}	
	return 0;
}

