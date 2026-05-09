#include<bits/stdc++.h>
using namespace std;
int n;
int prime[10005],cnt;
bool is_prime[10005]; 
int main(){
	memset(is_prime,true,sizeof(is_prime));
	scanf("%d",&n);
	is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>n)break;
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0)break;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",prime[i]);
	return 0;
}

