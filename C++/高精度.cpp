#include<bits/stdc++.h>
using namespace std;
string a1,b1;
int a[10005],b[10005];
int lena,lenb;
int answer[10005],cnt,aa[10005];
void add(int x[10005],int y[10005]){
	memset(answer,0,sizeof(answer));
	memset(aa,0,sizeof(aa));
	cnt=0;
	int tag=0;
	for(int i=lena;i>=1;i--){
		aa[++cnt]=(tag+x[i]+y[i])%10;
		tag=((tag+x[i]+y[i])-((tag+x[i]+y[i])%10))/10;
	}
	if(tag)aa[++cnt]=tag;
	for(int i=cnt;i>=1;i--)answer[cnt-i+1]=aa[i];
}
int bb[10005];
void mul(int x[10005],int y[10005]){
	memset(answer,0,sizeof(answer));
	memset(aa,0,sizeof(aa));
	cnt=0; 
	int tag=0;
	int cnt1=0;
	for(int i=lenb;i>=1;i--){
		for(int j=1;j<=cnt1;j++)bb[j]=0;
		cnt1=lenb-i;
		int tag2=0;
		for(int j=lena;j>=1;j--){
			bb[++cnt1]=(tag2+x[j]*y[i])%10;
			tag2=(tag2+x[j]*y[i]-((tag2+x[j]*y[i])%10))/10;
		}
		while(tag2){
			bb[++cnt1]=tag2%10;
			tag2/=10;
		}
		while(bb[cnt1]>=10){
			cnt1++;
			bb[cnt1]=bb[cnt1-1]/10;
			bb[cnt1-1]%=10;
		}
		tag2=0;
//		for(int j=1;j<=cnt1;j++)printf("%d",bb[j]);
//		printf("\n");
		
		for(int j=1;j<=max(cnt,cnt1);j++){
			int sum=aa[j]+bb[j]+tag2;
			bb[j]=(sum)%10;
			tag2=(sum-sum%10)/10;
	//		printf("check:%d ",tag2);
		}
		while(tag2){
			bb[++cnt1]=tag2%10;
			tag2/=10;
		}
		while(bb[cnt1]>=10){
			cnt1++;
			bb[cnt]=(bb[cnt1-1]-(bb[cnt-1]%10))/10;
			bb[cnt1-1]%=10;
		}
		cnt=max(cnt,cnt1);
		for(int j=1;j<=cnt;j++)aa[j]=bb[j];
		
//		for(int j=1;j<=cnt;j++)printf("%d",aa[j]);
//		printf("\n");
	}
	for(int i=cnt;i>=1&&!aa[i];i--)cnt--;
	for(int i=cnt;i>=1;i--)answer[cnt-i+1]=aa[i];
}
int main(){
	cin>>a1>>b1;
	if(a1.size()<b1.size())swap(a1,b1);
	for(int i=0;i<a1.size();i++)a[++lena]=a1[i]-'0';
	for(int i=0;i<a1.size()-b1.size();i++)b[++lenb]=0;
	for(int i=0;i<b1.size();i++)b[++lenb]=b1[i]-'0';
	add(a,b);
	printf("add:");
	for(int i=1;i<=cnt;i++)printf("%d",answer[i]);printf("\n");
	mul(a,b);
	printf("mult:");
	for(int i=1;i<=cnt;i++)printf("%d",answer[i]);printf("\n");
	return 0;
}

