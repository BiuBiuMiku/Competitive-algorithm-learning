#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
int n,m; 
struct edge{
	int from,to,next;
}E[maxm];
int head[maxm],cnt;
void add(int x,int y){
	E[++cnt].from=x;
	E[cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
int T;
int ans[maxm],t;
int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=cnt;i++)E[i].from=E[i].to=E[i].next=0;
		for(int i=1;i<=n;i++)head[i]=0;
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=head[i];j;j=E[j].next)
				ans[++t]=E[j].to;
			sort(ans+1,ans+1+t);
			for(int j=1;j<=t;j++)printf("%d ",ans[j]);
			printf("\n");
		}
	
	}
	
	return 0;
}

