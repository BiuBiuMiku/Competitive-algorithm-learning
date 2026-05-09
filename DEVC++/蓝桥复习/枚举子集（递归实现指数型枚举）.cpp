#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int cnt,string ans){
	if(cnt==n){
		cout<<ans<<endl;
		return;
	}
	dfs(cnt+1,ans+'N');
	dfs(cnt+1,ans+'Y');
}
int main(){
	scanf("%d",&n);
	dfs(0,"");
	return 0;
}

