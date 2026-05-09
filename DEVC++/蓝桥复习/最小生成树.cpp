#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,maxm=2e5+5; 
int n,m;
int f[maxn];
int getfather(int k){
	if(f[k]==k)return f[k];
	return f[k]=getfather(f[k]);
} 
struct edge{
	int x,y,z;
}e[maxm];
bool cmp(edge u,edge v) {return u.z<v.z;} 
int ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(getfather(e[i].x)!=getfather(e[i].y)){
			f[getfather(e[i].x)]=getfather(e[i].y);
			ans+=e[i].z;
			n--; 
		} 
		if(n==1)break;
	}
	if(n>1) printf("orz");
	else printf("%d",ans);

	return 0;
}

