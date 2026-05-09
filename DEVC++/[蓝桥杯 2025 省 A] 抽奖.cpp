#include<bits/stdc++.h>
using namespace std;
int n;
int ro[4][1005];
int cnt[4]; 
int a[4]; 
int m;
int score;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&ro[i][j]);
	scanf("%d",&m);
	cnt[1]=cnt[2]=cnt[3]=1; 
	while(m--){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		for(int i=1;i<=3;i++){
			if((cnt[i]+a[i])%n==0)cnt[i]=n;
			else cnt[i]=(cnt[i]+a[i])%n;
		}
		int n1=ro[1][cnt[1]],n2=ro[2][cnt[2]],n3=ro[3][cnt[3]];
		int add=0; 
		if(n1==n2-1 && n2==n3-1)add=max(200,add);
		if(n1==n2 && n2==n3)add=max(200,add);
		if(n1==n2 || n1==n3 || n2==n3)add=max(100,add);
		if(n1>n2)swap(n1,n2);
		if(n1>n3)swap(n1,n3);
		if(n2>n3)swap(n2,n3); 
		if(n1==n2-1 && n2==n3-1)add=max(100,add);
		score+=add; 
	} 
	printf("%d",score);

	return 0;
}

