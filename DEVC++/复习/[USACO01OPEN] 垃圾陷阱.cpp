#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+5;
int D,G;
int dp[105][105];
struct rubbish{
	int f,t,h;
}a[105];
int ans=oo;
int tim;
int sum=10;
int main(){
	scanf("%d%d",&D,&G);
	memset(dp,oo,sizeof(dp));
	for(int i=1;i<=G;i++)
		scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
	dp[0][10]=0;
	for(int i=1;i<=G;i++){
		sum+=a[i].t;
		for(int Heigh=D;Heigh>=a[i].h;Heigh--)
			for(int Power=a[i].f;Power<=sum;Power++){	
				int cv=min(dp[Heigh-a[i].h][Power+a[i].t]+a[i].t,dp[Heigh][Power-a[i].f+a[i].t]+a[i].t);
				dp[Heigh][Power]=min(dp[Heigh][Power],cv);
			}
	}
	for(int i=0;i<=sum;i++)
		ans=min(ans,dp[D][i]);
	for(int i=D;i>=0;i--)
		tim=max((dp[i][0]==oo?0:dp[i][0]),tim);
	if(ans==oo)printf("%d",tim);
	else printf("%d",ans);
	return 0;
}
/*
对于第n个物品  t,f,h
dp[0][10]=0;
Heigh D~h[i]
Power f[i]~Sum
Sum t[i] 

dp[Heigh][Power]
min
dp[Heigh][Power]
dp[Heigh-h[i]][Power+t[i]]+t[i] 
dp[Heigh][Power-f[i]+t[i]]+t[i]


*/
