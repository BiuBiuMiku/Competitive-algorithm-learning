#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5; 
int n,ans;
long long m;
long long l,r,mid,us;
int a[maxn],b[maxn]; 
bool check(long long x){
	us=0;
	for(int i=1;i<=n;i++){
		if(x>a[i]){
			if(b[i]<x-a[i])return false;
			us+=x-a[i];
		}
	} 
	if(us<=m)return true;
	return false;
} 
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	l=1;r=2*maxn+1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}

