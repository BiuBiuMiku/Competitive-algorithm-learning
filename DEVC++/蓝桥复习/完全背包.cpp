#include<bits/stdc++.h>
using namespace std;
const int maxt=1e7+5; 
long long T,M;
long long f[maxt]; 
signed main(){
	scanf("%lld%lld",&T,&M);
	for(int i=1;i<=M;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		for(int j=x;j<=T;j++)
			f[j]=max(f[j-x]+y,f[j]);
	}
	printf("%lld",f[T]);
	return 0;
}

