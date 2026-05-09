#include<bits/stdc++.h>
using namespace std;
int prime[10005],cnt;
bool is_prime[100005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	memset(is_prime,true,sizeof(is_prime));
	for(int i=2;i<=20250;i++){
		if(is_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>20250)break;
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0)break;
		}
	}
	printf("%d",prime[2025]);

	return 0;
}

