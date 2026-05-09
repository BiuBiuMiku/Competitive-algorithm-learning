#include<bits/stdc++.h>
#define Left (root<<1)
#define Right ((root<<1)+1)
using namespace std;
const int maxn=1e6+5;
int n,m;
long long a[maxn];
struct SegTree{
	struct SeTree{
		int ls,rs;
		long long val,tag;
	}T[(maxn<<1)+2];
	void Push_Up(int root){T[root].val=T[Left].val+T[Right].val;}
	void Push_Down(int root){
		if(T[root].tag){
			T[Left].val=T[Left].val+(T[Left].rs-T[Left].ls+1)*T[root].tag;
			T[Right].val=T[Right].val+(T[Right].rs-T[Right].ls+1)*T[root].tag;
			T[Left].tag+=T[root].tag;
			T[Right].tag+=T[root].tag;
			T[root].tag=0;
		}
	}
	void Build(int root,int l,int r){
		T[root].ls=l,T[root].rs=r;
		if(l==r){
			T[root].val=a[l];
			return;
		}
		Build(Left,l,(l+r)>>1);
		Build(Right,((l+r)>>1)+1,r);
		Push_Up(root);
	}
	void Update(int root,int l,int r,long long val){
		if(T[root].ls>r || T[root].rs<l)return;
		if(T[root].ls>=l && T[root].rs<=r){
			T[root].val=T[root].val+(T[root].rs-T[root].ls+1)*val;
			T[root].tag+=val;
			return;
		}
		Push_Down(root);
		Update(Left,l,r,val);
		Update(Right,l,r,val);
		Push_Up(root);
	}
	long long Query(int root,int l,int r){
		if(T[root].ls>r || T[root].rs<l)return 0;
		if(T[root].ls>=l && T[root].rs<=r)return T[root].val;
		Push_Down(root);
		return Query(Left,l,r)+Query(Right,l,r);
	}
}Tree;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	Tree.Build(1,1,n);
	for(int i=1;i<=m;i++){
		int x,y,z;
		long long d;
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%lld",&y,&z,&d);
			Tree.Update(1,y,z,d);
		}
		else{
			scanf("%d%d",&y,&z);
			printf("%lld\n",Tree.Query(1,y,z));
		}
	}
	return 0;
}

