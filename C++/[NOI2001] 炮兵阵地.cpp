#include<bits/stdc++.h>
using namespace std;
int n,m;
bool map1[105][15];
int ma[105];	
int f[105][2049];
int dp[105][2049][2049];
int answer=0;
void dfs(int x,int sit,int sum,int cd){
	if(sit==m){
		f[x][cd]=sum;
		return;
	}
	dfs(x,sit+1,sum,cd<<1);
	if(map1[x][sit+1] && !(cd&3) )
		dfs(x,sit+1,sum+1,(cd<<1)+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			if(ch=='P')map1[i][j]=true;
			else ma[i]+=1;
			ma[i]=ma[i]<<1;
		}
		ma[i]>>=1;
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,0,0); 
	for(int i=0;i<=(1<<(m+1));i++)
		dp[1][0][i]=f[1][i];
	for(int i=0;i<=(1<<(m+1));i++){
		if( (i&(i<<1))!=0 || (i&(i<<2))!=0 || (i&ma[1])!=0 )continue;
		for(int j=0;j<=(1<<(m+1));j++){
			if( (j&(j<<1))!=0 || (j&(j<<2))!=0 || (j&ma[2])!=0 )continue;
			if( (i&j)!=0 )continue;
			dp[2][i][j]=max(dp[2][i][j],dp[1][0][i]+f[2][j]);
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=(1<<m+1);j++){
			if( (j&(j<<1))!=0 || (j&(j<<2))!=0 || (j&ma[i-2])!=0 ) continue;
			for(int k=0;k<=(1<<m+1);k++){
				if( (k&(k<<1))!=0 || (k&(k<<2))!=0 || (k&ma[i-1])!=0 ) continue;
				if( (j&k)!=0 ) continue;
				for(int t=0;t<=(1<<m+1);t++){
					if( (t&(t<<1))!=0 || (t&(t<<2))!=0 || (t&ma[i])!=0 ) continue;
					if( (t&k)!=0 || (t&j)!=0 ) continue;
					dp[i][k][t]=max(dp[i][k][t],dp[i-1][j][k]+f[i][t]);
				}
			}
		}
	}
	for(int i=0;i<=(1<<m+1);i++)
		for(int j=0;j<=(1<<m+1);j++)
			answer=max(answer,dp[n][i][j]);
	printf("%d",answer);
	return 0;
}

