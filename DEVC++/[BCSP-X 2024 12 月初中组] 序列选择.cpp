#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
long long oo=2e10;
long long n;
long long a[maxn],b[maxn];
long long f[maxn][2];
long long answer;
//long long abs(long long x){
//	if(x<0)return -(x);
//	else return x; 
//}
signed main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(long long i=2;i<=n;i++){
		f[i][0]= min ( abs(a[i]-a[i-1])+f[i-1][0] , abs(a[i]-b[i-1])+f[i-1][1] ) ;
		f[i][1]= min ( abs(b[i]-a[i-1])+f[i-1][0] , abs(b[i]-b[i-1])+f[i-1][1] ) ;
	}
	answer=min(f[n][0],f[n][1]);
	printf("%lld",answer);
	return 0;
}

