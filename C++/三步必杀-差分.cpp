#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5;
int n,m;
long long a[MAXN];
int b[MAXN],c[MAXN],d[MAXN];
long long l,r,s,e,ad;
long long ans1,ans2;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%lld%lld%lld%lld",&l,&r,&s,&e);
		ad=(e-s)/(r-l); 
		c[l]+=ad;c[r+1]-=ad;
		b[l]+=(s-ad);b[r+1]-=e; 
	}
	for(int i=1;i<=n;i++)d[i]=d[i-1]+c[i];
	for(int i=1;i<=n;i++)d[i]+=b[i];
	for(int i=1;i<=n;i++)a[i]=d[i]+a[i-1];
	ans1=a[1];
	for(int i=2;i<=n;i++){
		ans1=ans1^a[i];
		ans2=max(ans2,a[i]);
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}

