#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int a[maxn];
int sum[maxn]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	scanf("%d",&m);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}

	return 0;
}

