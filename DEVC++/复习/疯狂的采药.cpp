#include<bits/stdc++.h>
using namespace std;
int T,M;
int f[1005]; 
int a[105],b[105];
int main(){
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=M;i++)
		for(int j=a[i];j<=T;j++)
			f[j]=max(f[j],f[j-a[i]]+b[i]);
	printf("%d",f[T]);
	return 0;
}

