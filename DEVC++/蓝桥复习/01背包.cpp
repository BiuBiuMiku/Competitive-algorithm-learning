#include<bits/stdc++.h>
using namespace std;
int T,M;
int f[1005]; 
int main(){
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=T;j>=x;j--)
			f[j]=max(f[j-x]+y,f[j]);
	}
	printf("%d",f[T]);
	return 0;
}

