#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=1e6+5;
int N,M;
int f[maxn];
int getfather(int k){
	if(f[k]==k)return f[k];
	return f[k]=getfather(f[k]);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)f[i]=i;
	for(int i=1;i<=M;i++){
		int z,x,y;
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)f[getfather(x)]=getfather(y);
		else{
			if(getfather(x)!=getfather(y))printf("N\n");
			else printf("Y\n");
		}
	}

	return 0;
}

