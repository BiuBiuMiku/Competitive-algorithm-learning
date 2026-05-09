#include <bits/stdc++.h>
using namespace std;
int m;
int n,cnt1=1,cnt2=3,rcnt=3;
long long maxn=(1<<26); 
long long pl,kl,k;
bool a[(1<<26)+5]; 
int main(){	
	a[1]=true;a[2]=false;
	for(cnt2=3;cnt2<=maxn;){
		a[cnt2++]=(!a[cnt1++])?true:false;
		if(cnt1==rcnt)rcnt=cnt2,cnt1=1;
	}
//	for(int i=1;i<=maxn;i++)printf((a[i])?"R":"B");
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%lld",&n,&k);
		pl=k%maxn,kl=k/maxn;
		if(pl==0)pl=maxn; 
		if(kl==0 || kl==3 ||kl==5 || kl==6){
			if(a[pl]==true)cout<<"RED\n";
			else cout<<"BLACK\n";
		}
		else{
			if(a[pl]==false)cout<<"RED\n";
			else cout<<"BLACK\n";
		} 
	
	}
	return 0;
}


