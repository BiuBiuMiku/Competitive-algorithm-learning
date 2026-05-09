#include<bits/stdc++.h>
using namespace std;
int n,m,N,M;
int cur;
int a[105];
int ou[105][105];
void ot(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<ou[i][j]<<" ";
		cout<<endl;
	}
}
void draw(){
	cur=0;
	while(1){
		if(cur>=n*m)return;
		for(int i=n-N+1;i<=N;i++) {ou[i][m-M+1]=a[++cur];if(cur>n*m)return;}
		if(cur>=n*m)return;
	//	ot();
		for(int i=m-M+1+1;i<=M;i++) {ou[N][i]=a[++cur];if(cur>n*m)return;}
		if(cur>=n*m)return;
	//	ot();
		for(int i=1;i<N;i++) {ou[N-i][M]=a[++cur];if(cur>n*m)return;}
		if(cur>=n*m)return;
	//	ot();
		for(int i=1;i<M-1;i++) {ou[n-N+1][M-i]=a[++cur];if(cur>n*m)return;}
		if(cur>=n*m)return;
	//	ot();
		N--,M--;
		
	}
}
bool cmp(int a,int b){return (a<b);}
int main(){
	scanf("%d%d",&n,&m);
	N=n;M=m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n*m,cmp); 
	draw(); 
	ot();
	for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	return 0;
}

