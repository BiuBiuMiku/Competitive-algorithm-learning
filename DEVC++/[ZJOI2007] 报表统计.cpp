#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7+5,oo=1e9;
int ans1,ans2;
map<int,int> sam;
inline int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	if(f)return x;else return -x;
}
struct FHQ_Treap{
	struct FHQ{
		int ls,rs,fix;
		int val,size; 
	}fhq[maxn];
	int root,cnt;
	void Update(int x){fhq[x].size=fhq[fhq[x].ls].size+fhq[fhq[x].rs].size+1;}
	inline int New_Node(int val){
		fhq[++cnt].fix=rand();
		fhq[cnt].val=val;
		fhq[cnt].size=1;
		return cnt;	
	}
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
	int Merge(int x,int y){
		if(!x||!y)return x+y;
		if(fhq[x].fix>=fhq[y].fix){
			fhq[x].rs=Merge(fhq[x].rs,y);
			Update(x);
			return x;
		}
		else{
			fhq[y].ls=Merge(x,fhq[y].ls);
			Update(y);
			return y;
		}
	}
	inline void Insert(int val){
		int x=0,y=0;
		Split(root,val,x,y);
		root=Merge(Merge(x,New_Node(val)),y);
	}
	inline void Delete(int val){
		int x=0,y=0,z=0;
		Split(root,val,x,z);
		Split(x,val-1,x,y);
		y=Merge(fhq[y].ls,fhq[y].rs);
		x=Merge(x,y);
		root=Merge(x,z);
	}
	inline int Prev(int val){
		int x=0,y=0;
		Split(root,val-1,x,y);
		int now=x;
		if(!now){
			root=Merge(x,y);
			return oo;
		}
		while(fhq[now].rs)now=fhq[now].rs;
		root=Merge(x,y);
		return fhq[now].val;
	}
	inline int Succ(int val){
		int x=0,y=0;
		Split(root,val,x,y);
		int now=y;
		if(!now){
			root=Merge(x,y);
			return oo;
		}
		while(fhq[now].ls)now=fhq[now].ls;
		root=Merge(x,y);
		return fhq[now].val;
	}
}T1,T2; 
int n,m,a[maxn];
int b[maxn];
signed main(){
	ans1=ans2=oo;
	srand(time(NULL));
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sam[a[i]]++;
		if(sam[a[i]]>1)ans2=0;
		b[i]=a[i];
		if(i!=1)T1.Insert(abs(a[i]-a[i-1]));
		T2.Insert(a[i]);
		int pre=T2.Prev(a[i]),suc=T2.Succ(a[i]);
		if(pre!=oo)ans2=min(ans2,abs(a[i]-pre));
		if(suc!=oo)ans2=min(ans2,abs(a[i]-suc));
	}
	for(int i=1;i<=m;i++){
		string str;
		cin>>str;
		if(str=="INSERT"){
			int x=read(),y=read();
			sam[y]++;
			if(sam[y]>1)ans2=0;
			if(x!=n){
				T1.Delete( abs(b[x]-a[x+1]));
				T1.Insert( abs(y-a[x+1]) );
			}
			T1.Insert( abs(b[x]-y) );
			b[x]=y;
			T2.Insert(y);
			int pre=T2.Prev(y),suc=T2.Succ(y);
			if(pre!=oo)ans2=min(ans2,abs(y-pre));
			if(suc!=oo)ans2=min(ans2,abs(y-suc));
		}
		if(str=="MIN_GAP"){
			int now=T1.root;
			while(T1.fhq[now].ls)now=T1.fhq[now].ls;
			printf("%d\n",T1.fhq[now].val);
		}
		if(str=="MIN_SORT_GAP")printf("%d\n",ans2);
	}
	return 0;
}
