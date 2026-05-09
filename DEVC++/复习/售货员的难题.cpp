#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+5;
int n;
int f[(1<<20)][105],w[105][105];
int ans=oo;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	memset(f,oo,sizeof(f));
	f[1][1]=0;
	for(int i=0;i<=(1<<n)-1;i++)
		for(int j=1;j<=n;j++){
			if(!((i>>(j-1))&1))continue;
			for(int k=2;k<=n;k++){
				if(j==k)continue;
				if(((i>>(k-1))&1))continue;
				f[i+(1<<(k-1))][k]=min(f[i+(1<<(k-1))][k],f[i][j]+w[j][k]);
			}	
		}
	for(int i=2;i<=n;i++)
		ans=min(ans,f[(1<<(n))-1][i]+w[i][1]);
	printf("%d",ans);
	return 0;
}
