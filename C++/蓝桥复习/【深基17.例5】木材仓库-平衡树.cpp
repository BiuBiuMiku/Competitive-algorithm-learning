#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Node{
	int size,ls,rs;
	int val,fix,id;
}fhq[maxn];
int cnt=0;
int New_Node(int sum){
	long long sd=1e6*2+5;
	fhq[++cnt].val=sum;
	fhq[cnt].size=1;
	fhq[cnt].id=cnt;
	fhq[cnt].fix=rand()%sd;
	return cnt;	
}
void Update(int x){
	fhq[x].size=0;
	fhq[x].size+=fhq[fhq[x].ls].size;
	fhq[x].size+=fhq[fhq[x].rs].size;
	fhq[x].size++;
}
int root;
void Split(int now,int val,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(fhq[now].val<=val){
			x=now;
			Split(fhq[now].rs,val,fhq[now].rs,y);
		}
		else{
			y=now;
			Split(fhq[now].ls,val,x,fhq[now].ls);
		}
		Update(now);
	}	
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(fhq[x].fix>=fhq[y].fix){
		fhq[x].rs=merge(fhq[x].rs,y);
		Update(x);
		return x;
	}
	else{
		fhq[y].ls=merge(x,fhq[y].ls);
		Update(y);
		return y;
	}
}
int prev(int val){
	int x=0,y=0;
	Split(root,val,x,y);
	int now=x;
	while(fhq[now].rs) now=fhq[now].rs;
	root=merge(x,y);
	return now;
}
int succ(int val){
	int x=0,y=0;
	Split(root,val-1,x,y);
	int now=y;
	while(fhq[now].ls) now=fhq[now].ls;
	root=merge(x,y);
	return now;
}
void Delete(int val){
	int x=0,y=0,z=0;
	Split(root,val,x,z);
	Split(x,val-1,x,y);
	y=merge(fhq[y].ls,fhq[y].rs);
	root=merge(merge(x,y),z);
}
void Insert(int val){
	int x=0,y=0;
	Split(root,val,x,y);
	int z=New_Node(val);
	root=merge(merge(x,z),y);
} 
int n;
int main(){
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	while(n--){
		int aa,bb;
		scanf("%d%d",&aa,&bb);
		if(aa==1){
			int lef=prev(bb);
		    int righ=succ(bb);
		    if((lef!=0&&fhq[lef].val==bb)||(righ!=0 && fhq[righ].val==bb)) {
		        printf("Already Exist\n");
		        continue;
		    }
			Insert(bb);
		}
		if(aa==2){
			if(!root) {printf("Empty\n");continue;}
			int lef=prev(bb),righ=succ(bb);
			int ans=0;
			if(!lef)ans=fhq[righ].val;
			else if(!righ)ans=fhq[lef].val;
			else {
				int vl=fhq[lef].val,vr=fhq[righ].val;
				if(abs(bb-vl)<=abs(bb-vr))ans=vl;
				else ans=vr;
			}
			printf("%d\n",ans);
			Delete(ans);
		}
	}
	return 0;
}

