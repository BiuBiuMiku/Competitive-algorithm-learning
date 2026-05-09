#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,oo=1e9;
int n;
int a[maxn];
int f[maxn];
int ans=-oo;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)f[i]=-oo;
	for(int i=1;i<=n;i++){
		f[i]=max(a[i],f[i-1]+a[i]);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);

	return 0;
}

