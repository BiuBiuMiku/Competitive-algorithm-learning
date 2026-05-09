#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
int n;
int a[maxn];
int f[maxn];
int l,r;
int p[maxn],q[maxn];
int main(){
	scanf("%d",&n);
	l=1,r=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		while(a[i]>=q[r] && l<=r ) r--;
		f[i]=p[r];
		p[++r]=i;
		q[r]=a[i];
	}	 
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	return 0;
}

