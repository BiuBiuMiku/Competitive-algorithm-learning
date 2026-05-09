#include<bits/stdc++.h>
using namespace std;
long long T,m;
long long ti[1005],val[1005];
long long f[1005]; 
long long main(){
	scanf("%d%d",&T,&m);
	for(long long i=1;i<=m;i++)scanf("%d%d",&ti[i],&val[i]);
	for(long long i=1;i<=m;i++)
		for(long long j=T;j>=ti[i];j--)
			f[j]=max(f[j-ti[i]]+val[i],f[j]);
	printf("%d",f[T]);	
	return 0;
}

