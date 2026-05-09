#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[28];
queue<int> q; 
struct edge{
	int from,to,next;
}E[605];
int head[28],cnt;
void add(int x,int y){
	E[++cnt].from=x;
	E[cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt; 
} 
string answer,non;
int st;
bool vis[29];
int b[28];
bool circle,sho[28];
int N,now[29];
int rel; 
void work(){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)b[i]=a[i],vis[i]=false;
	st=0,rel=0,answer=non;
	for(int i=1;i<=N;i++)
		if(b[now[i]]==0)rel++,st=now[i],q.push(now[i]);
	if(!rel){circle=true;return;} 
	answer+=char(st+'A'-1);
	while(!q.empty()){
		if(rel>1)answer=non;
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			b[v]--; 
			if(b[v]==0){
				q.push(v);
				if(answer[answer.size()-1]==(u+'A'-1))answer+=char(v+'A'-1);
				else answer=non;
			} 
		}
	}
} 
string str;
map<string,bool> check; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		cin>>str;
		if(check[str])continue;
		check[str]=true;
		int u=str[0]-'A'+1,v=str[2]-'A'+1;
		if(u==v) {printf("Inconsistency found after %d relations.",i);return 0;}
		if(!sho[u])sho[u]=true,now[++N]=u;
		if(!sho[v])sho[v]=true,now[++N]=v;
		add(u,v);a[v]++;work();	
		for(int j=1;j<=N;j++)if(b[now[j]]!=0)circle=true; 
		if(circle) {printf("Inconsistency found after %d relations.",i);return 0;}
		if(answer.size()==n){cout<<"Sorted sequence determined after "<<i<<" relations: "<<answer<<".";return 0;}
	}
	printf("Sorted sequence cannot be determined."); 
	return 0;
}

