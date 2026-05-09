#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5; 
int n,m;
int l[maxn],r[maxn]; 
bool dead[maxn];
void left_insert(int x,int y){
	if(x==y)return;
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	r[l[y]]=x; 
	l[x]=l[y];
	l[y]=x;
	r[x]=y;
}
void right_insert(int x,int y){
	if(x==y)return;
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	l[r[y]]=x;
	r[x]=r[y];
	r[y]=x;
	l[x]=y;
}
void del(int x){
	dead[x]=true;
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	l[x]=r[x]=0;
}
void sta(){
	for(int i=1;i<=n;i++){
		if(i!=1)l[i]=i-1;
		if(i!=n)r[i]=i+1;
	}
}
void check(){
	printf("check\n");
	for(int i=1;i<=n;i++){
		printf("num:%d left:%d right:%d\n",i,l[i],r[i]);
	}
	printf("\n");
}
int head;
int main(){
	scanf("%d%d",&n,&m);
	sta();
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d",&y,&z);
			left_insert(y,z);
		}
		if(x==2){
			scanf("%d%d",&y,&z);
			right_insert(y,z);
		}	
		if(x==3){
			scanf("%d",&y);
			del(y);
		}
	//	check();
	}
	for(int i=1;i<=n;i++)
		if(l[i]==0&&!dead[i]){
			head=i;
			break;
		}
	if(head==0)printf("Empty!");
	else for(int i=head;i;i=r[i])
			printf("%d ",i);
	return 0;
}

