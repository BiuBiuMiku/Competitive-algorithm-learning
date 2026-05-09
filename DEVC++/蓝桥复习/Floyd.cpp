#include<bits/stdc++.h>
using namespace std;
const long long oo=1e10;
long long n,m;
long long f[105][105];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			f[i][j]=oo;
	for(long long i=1;i<=n;i++)f[i][i]=0;
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		f[x][y]=min(f[x][y],z);
		f[y][x]=min(f[y][x],z);
	}
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)	
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			printf("%lld ",f[i][j]);
		printf("\n");
	}
	return 0;
}

