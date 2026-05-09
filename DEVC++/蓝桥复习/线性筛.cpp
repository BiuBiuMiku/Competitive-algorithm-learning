#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+5; 
bool is_prime[maxn];
int prime[maxn];
int cnt,n,m; 
int main(){
	memset(is_prime,true,sizeof(is_prime));
	scanf("%d%d",&n,&m);
	is_prime[1]=false; 
	for(int i=2;i<=n;i++){
		if(is_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>n)break;
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		printf("%d\n",prime[t]);
	}

	return 0;
}

