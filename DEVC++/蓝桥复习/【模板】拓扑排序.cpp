#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,next;
}E[10005];
int head[105],cnt;
void add(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
} 
int n;
queue<int> q;
int a[105]; 
int ans[105],m; 
void topsort(){
	for(int i=1;i<=n;i++)
		if(a[i]==0){
			ans[++m]=i; 
			q.push(i);	
		}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			a[v]--;
			if(a[v]==0){
				q.push(v);
				ans[++m]=v;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int ed=1;
		while(1){
			scanf("%d",&ed);
			if(ed==0)break; 
			add(i,ed);
			a[ed]++; 
		}
	}
	topsort();
	for(int i=1;i<=m;i++)printf("%d ",ans[i]); 
	return 0;
}

