#include<bits/stdc++.h>
using namespace std;
long long a,n,p; 
long long N,A;
long long answer=1;
int main(){
	scanf("%lld%lld%lld",&a,&n,&p);
	N=n;A=a;
	while(n>0){
		if(n&1)answer=(answer*a)%p;
		a%=p; a=(a*a)%p;
		n=n>>1;
	}
	printf("%lld^%lld mod %lld=%lld",A,N,p,answer);
	return 0;
}

