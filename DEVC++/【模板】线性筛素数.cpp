#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+5;
int prime[maxn];
bool is_prime[maxn];
int n,cnt,q;
int main(){
	scanf("%d%d",&n,&q);
	memset(is_prime,true,sizeof(is_prime));
	is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>n)break;
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=q;i++){
		int k;
		scanf("%d",&k);
		printf("%d\n",prime[k]);
	}
	return 0;
}

