#include<bits/stdc++.h>
using namespace std;
int n;
int ins[105];
struct edge{
	int from,next,to;
}e[100005];
int head[105],cnt;
int ans[105],k;
queue<int>q;
bool vis[105];
void add(int x,int y){
	e[++cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		while(1){
			int q;
			scanf("%d",&q);
			if(q==0)break;
			add(i,q);
			ins[q]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!ins[i]){
			q.push(i);	
			ans[++k]=i;
		}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			ins[v]--;
			if(!ins[v]){
				q.push(v);	
				ans[++k]=v;
			}
		}
	}
	for(int i=1;i<=k;i++)printf("%d ",ans[i]);
	return 0;
}

