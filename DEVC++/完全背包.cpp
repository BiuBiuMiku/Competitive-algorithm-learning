#include<bits/stdc++.h>
using namespace std;
const long long mmax=1e7+5; 
long long T,m;
long long ti[mmax],val[mmax];
long long f[mmax]; 
signed main(){
	scanf("%lld%lld",&T,&m);
	for(long long i=1;i<=m;i++)scanf("%lld%lld",&ti[i],&val[i]);
	for(long long i=1;i<=m;i++)
		for(long long j=ti[i];j<=T;j++)
			f[j]=max(f[j-ti[i]]+val[i],f[j]);
	printf("%lld",f[T]);	
	return 0;
}

