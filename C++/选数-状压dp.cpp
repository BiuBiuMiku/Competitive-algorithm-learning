#include<bits/stdc++.h>
using namespace std;
int T;
int n,m;
int num[9][9];
int f[9][10005];
int dp[9][10005];
int answer=0;
void dfs(int x,int sum,int sit,int cd){
	if(sit==m){
//		printf("check %d : %d\n",cd,sum);
		f[x][cd]=sum;
		return;
	}
	dfs(x,sum,sit+1,cd<<1);
	if(!(cd&1))dfs(x,sum+num[x][sit+1],sit+1,(cd<<1)+1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		answer=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&num[i][j]);
		for(int i=1;i<=n;i++)
			dfs(i,0,0,0);
	//	printf("check:%d\n",1<<(m+1));
		for(int i=0;i<=1<<(m+1);i++)dp[1][i]=f[1][i];
	//	printf("bug");
		for(int i=2;i<=n;i++){
			
			for(int j=0;j<=1<<(m+1);j++){
				if((j&(j<<1))!=0)continue;
				for(int k=0;k<=1<<(m+1);k++){
					if( (k&(k<<1))!=0 || (j&k)!=0 || (j&(k<<1))!=0 || ((j<<1)&k)!=0)continue; 
					dp[i][k]=max(dp[i][k],dp[i-1][j]+f[i][k]);
				}
			}
//			int chek=0;
//			for(int j=0;j<=1<<(m+1);j++)chek=max(chek,dp[i][j]);
//			printf("check:%d\n",chek);
		}
		for(int i=0;i<=1<<(m+1);i++)answer=max(answer,dp[n][i]);
		printf("%d\n",answer);
	}
	
	return 0;
}

