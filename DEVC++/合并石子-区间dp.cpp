#include<bits/stdc++.h>
using namespace std;
const int oo=1e9;
int n;
int a[305];
int f[305][305];
int sum[305]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=oo;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		f[i][i]=0;
		f[i-1][i]=a[i-1]+a[i];
	}
	for(int len=2;len<n;len++){
		for(int i=1;i<=n-len;i++){
			int j=i+len;
			for(int k=i;k<=j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
		}
	}
//	printf("%d\n",f[3][4]);
	printf("%d",f[1][n]);
	return 0;
}
