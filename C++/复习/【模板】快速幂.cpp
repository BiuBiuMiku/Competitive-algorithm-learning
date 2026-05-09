#include<bits/stdc++.h>
using namespace std;
long long a,b,p;
long long ans=1;
int main(){
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=",a,b,p);
	while(b){
		if(b&1)ans=(ans*a)%p;
		b=b>>1;
		a=((a%p)*(a%p))%p;
	}
	printf("%lld",ans);

	return 0;
}

