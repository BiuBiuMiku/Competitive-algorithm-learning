#include<bits/stdc++.h>
using namespace std;
long long f[226][(1<<15)+1];
long long dp[226][(1<<15)+1];
long long n,m;
long long a[226][226];
long long b[226][226];
long long cnt[225];
void change(){
	if(n<m){
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=m;j++)
				a[j][i]=b[i][j];
		swap(n,m);
	}
	else{
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=m;j++)
				a[i][j]=b[i][j];
	}
}
void dfs(long long x,long long now,long long sit){
	if(sit==m+1){
		f[x][++cnt[x]]=now;
		return;
	}
	if(a[x][sit]==3){
		if(!(now&1) && a[x][sit+1]!=1 )dfs(x,(now<<1)+1,sit+1);
		dfs(x,now<<1,sit+1);
		
	}
	else dfs(x,(now<<1)+a[x][sit],sit+1);
}
long long ans;
const long long mod=10007;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){	
		string str;
		cin>>str;
		for(long long j=0;j<str.size();j++){
			if(str[j]!='.')b[i][j+1]=str[j]-'0';
			else b[i][j+1]=3;
		}
	}
	change();
	for(long long i=1;i<=n;i++)
		dfs(i,0,1);
	for(long long i=1;i<=cnt[1];i++)
			dp[1][f[1][i]]=1;
	for(long long k=2;k<=n;k++)
		for(long long i=1;i<=cnt[k-1];i++){
			for(long long j=1;j<=cnt[k];j++){
				if(f[k-1][i]&f[k][j])continue;
				dp[k][f[k][j]]=(dp[k][f[k][j]]+dp[k-1][f[k-1][i]])%mod;
			}
		}
	for(long long i=1;i<=cnt[n];i++)
		ans=(ans+dp[n][f[n][i]])%mod;
	printf("%lld",ans);
	return 0;
}

