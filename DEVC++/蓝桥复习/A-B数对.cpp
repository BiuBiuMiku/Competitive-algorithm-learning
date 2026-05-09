#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,C;
map<int,int> a; 
int b[maxn];
int ans;
int main(){
	scanf("%d%d",&N,&C);
	for(int i=1;i<=N;i++){
		scanf("%d",&b[i]);
		a[b[i]]++;
	}
	for(int i=1;i<=N;i++)ans+=a[b[i]-C];
	printf("%d",ans);
	return 0;
}

