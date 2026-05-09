#include<bits/stdc++.h>
using namespace std;
long long a,b,p; 
long long na,nb; 
long long ans=1;
signed main(){
	scanf("%lld%lld%lld",&a,&b,&p);
	na=a,nb=b;
	while(b){
	//	printf("check:%d\n",b&1); 
		if((b&1)!=0)ans=(ans*(a%p))%p; 
		a=((a%p)*(a%p))%p;
		b=b>>1;
	}
	printf("%lld^%lld mod %lld=%lld",na,nb,p,ans);
	return 0;
}

