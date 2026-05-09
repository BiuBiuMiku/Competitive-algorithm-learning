#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,k;
int a[maxn];
int l,r,p[maxn],q[maxn];
int main(){
	scanf("%d%d",&n,&k);
	l=1,r=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(a[i]<=q[r] && l<=r)r--;
		q[++r]=a[i];
		p[r]=i;
		while(p[l]<=i-k && l<=r)l++;
		if(i>=k)printf("%d ",q[l]);
	}
	printf("\n");
	l=1,r=0;
	for(int i=1;i<=n;i++){
		while(a[i]>=q[r] && l<=r)r--;
		q[++r]=a[i];
		p[r]=i;
		while(p[l]<=i-k && l<=r)l++;
		if(i>=k)printf("%d ",q[l]);
	}
	return 0;
}

