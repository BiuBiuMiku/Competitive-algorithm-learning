#include<bits/stdc++.h>
using namespace std;
long long f[25][25][25];
long long a[25];
long long n,k;
long long ans=0;
signed main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)
		f[i][i][0]=a[i];
	for(long long i=1;i<n;i++){
		f[i][i+1][0]=a[i]+a[i+1];
		if(k!=0)f[i][i+1][1]=a[i]*a[i+1];
	}
	for(long long len=2;len<n;len++){
		for(long long i=1;i<=n-len;i++){
			long long j=i+len;
			for(long long mid=i+1;mid<j;mid++){
				for(long long x=0;x<=min(k,len);x++)
					for(long long y=0;y<=min(k,len);y++){
						if(x>mid-i||y>j-(mid+1)||x+y>min(k,len))continue;
						if(x+y+1<=k)f[i][j][x+y+1]=max(f[i][j][x+y+1],f[i][mid][x]*f[mid+1][j][y]);
						f[i][j][x+y]=max(f[i][j][x+y],f[i][mid][x]+f[mid+1][j][y]);
					}
			}
		}
	}
	printf("%lld",f[1][n][k]);
	return 0;
}

