#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[15];
void dfs(int cnt,string ans){
	if(cnt==k){
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0)continue;	
		a[i]++;
		dfs(cnt+1,ans+char(i+'0'));
		a[i]--;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	dfs(0,"");
	return 0;
}

