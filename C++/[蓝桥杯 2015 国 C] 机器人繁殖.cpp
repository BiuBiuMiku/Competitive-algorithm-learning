#include<bits/stdc++.h>
using namespace std;
int n;
int l,r,mid;
int cnta,cntb;
int a[500005],b[500005];
int re[500005],cnt; 
void ou(){
	printf("\n");
	for(int i=cnta;i>=1;i--)printf("%d",a[i]);printf("\n");
	for(int i=cntb;i>=1;i--)printf("%d",b[i]);printf("\n");
} 
int check(int num){
	for(int i=1;i<=cnta;i++)a[i]=0;
	for(int i=1;i<=cntb;i++)b[i]=0; 
	cnta=cntb=0; 
	while(num){
		a[++cnta]=num%10;
		b[++cntb]=num%10;
		num/=10; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cntb;j++)
			b[j]=b[j]*2; 
		b[1]-=1;
		for(int j=1;j<=cntb && b[j]<0;j++) b[j]=9,b[j+1]--;
		for(int j=1;j<cntb;j++)
			if(b[j]>=10){
				int k=b[j]/10;
				b[j+1]+=k;
				b[j]%=10;
			}
		while(b[cntb]>=10){
			int k=b[cntb]/10;
			b[cntb]%=10;
			b[++cntb]+=k;
		}
		for(int j=1;j<=max(cnta,cntb);j++)
			a[j]+=b[j];
		cnta=max(cnta,cntb); 
		for(int j=1;j<cnta;j++)
			if(a[j]>=10){
				int k=a[j]/10;
				a[j+1]+=k;
				a[j]%=10;
			}
		while(a[cnta]>=10){
			int k=a[cnta]/10;
			a[cnta]%=10;
			a[cnta+1]+=k;
			cnta++; 
		}
	}
	if(cnta<cnt) return 1;
	if(cnta>cnt) return 0;
	for(int i=cnta;i>=1;i--){
		if(re[i]>a[i])return 1;
		if(re[i]<a[i])return 0;
	}
	return 2;
} 
string str;
int main(){
	scanf("%d",&n);
	cin>>str;	
	int len=str.size();
	for(int i=len-1;i>=0;i--)re[++cnt]=int(str[i]-'0');
	l=1,r=1e6+5;
	while(l<=r){
		mid=(l+r)/2;  
		int k=check(mid);
		if(k==0)r=mid-1;
		else if(k==1)l=mid+1;
		else if(k==2){printf("%d",mid);return 0;}
	}
	return 0;
}

