#include<bits/stdc++.h>
using namespace std;
int n;
bool is[1000005];
int num[1000005];
int cnt;
int main(){
	scanf("%d",&n);
	memset(is,true,sizeof(is));
	is[2]=is[3]=true;
	for(int i=2;i<=n;i++){
		if(is[i])num[++cnt]=i;
		for(int j=i*i;j<=n;j+=i)
			is[j]=false;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",num[i]);
	return 0;
}

