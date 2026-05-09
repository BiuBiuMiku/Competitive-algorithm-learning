#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int maxm=2e5+5;
int n,m;
int f[maxn];
int getfather(int k){
	if(f[k]==k)return f[k];
	return f[k]=getfather(f[k]);
}
struct edge{
	int x,y,v;
}e[maxm];
int k=1,ans;
bool cmp(edge x,edge y){return x.v<y.v;}
int main(){
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++)f[i]=i;
 	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(k==n)break;
		if(getfather(e[i].x)!=getfather(e[i].y)){
			f[getfather(e[i].x)]=getfather(e[i].y);
			ans+=e[i].v;
			k++;
		}
	}
	if(k>=n)printf("%d",ans);
	else printf("orz");

	return 0;
}

