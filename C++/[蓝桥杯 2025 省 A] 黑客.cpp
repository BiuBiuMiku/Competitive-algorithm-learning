#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007; 
const long long maxn=5e5+5;
long long n,cnt;
long long a[maxn],num[maxn]; 
long long mmax=0;
long long sum[maxn],minu=1,prim;
long long plu(long long x){
	long long Su=1;
	for(long long i=1;i<=x;i++)
		Su=(Su*i)%mod;
	return Su;
} 
long long ans=0;

long long powmod(long long a, long long b) {
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

signed main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long x; 
		scanf("%lld",&x);
		a[x]++; 
		mmax=max(mmax,x);
	} 
	for(long long i=1;i<=mmax;i++)
		if(a[i]!=0)num[++cnt]=i; 
	for(long long i=1;i<=cnt;i++){
		sum[i]=plu(a[num[i]]);
		minu=(minu*sum[i])%mod;
	}
	n-=2;
	prim=plu(n); 
	for(long long i=1;i<=cnt;i++){
		if(n%num[i]==0 && a[n/num[i]]!=0){
			if(num[i]!=(n/num[i])){
				long long x=a[num[i]],y=a[n/num[i]];
				long long temp=prim;
				temp=temp*powmod(minu,mod-2)%mod;
				temp=temp*plu(x)%mod;
				temp=temp*plu(y)%mod;
				temp=temp*powmod(plu(x-1),mod-2)%mod;
				temp=temp*powmod(plu(y-1),mod-2)%mod;
				ans=(ans+temp)%mod;
			}
			else{
				long long temp=prim;
				temp=temp*powmod(minu,mod-2)%mod;
				temp=temp*plu(a[num[i]])%mod;
				temp=temp*powmod(plu(a[num[i]]-2),mod-2)%mod;
				ans=(ans+temp)%mod;
			}
		}
	}
	printf("%lld",ans); 
	return 0;
}
