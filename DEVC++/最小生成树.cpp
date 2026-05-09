#include<bits/stdc++.h>
using namespace std;
const int MAXM=2e5+5;
int n,m;
struct edge{
	int from,to,val;
}e[MAXM];
int f[5005];
int getfather(int k){
	if(f[k]==k)return k;
	return f[k]=getfather(f[k]);
} 
bool cmp(edge x,edge y){return x.val<y.val;}
int answer=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].val);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(getfather(e[i].from)!=getfather(e[i].to)){
			f[getfather(e[i].from)]=getfather(e[i].to);
			answer+=e[i].val;
			n--;
		}
		if(n==1)break;
	}
	if(n>1)printf("orz\n");
	else printf("%d",answer);
	return 0;
}

