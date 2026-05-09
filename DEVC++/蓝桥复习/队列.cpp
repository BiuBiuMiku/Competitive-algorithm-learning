#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6+5;
long long n,l,r,d;
unsigned long long a[maxn];
unsigned long long num;
signed main(){
	scanf("%lld",&n);
	l=r=1;
	for(long long i=1;i<=n;i++){
		cin>>d;
		if(d==1){
			cin>>num;
			a[r++]=num;
		}
		if(d==2){
			if(l-r==0)printf("ERR_CANNOT_POP\n");
			else l++;
		}
		if(d==3){
			if(l-r==0)printf("ERR_CANNOT_QUERY\n");
			else cout<<a[l]<<endl;
		}
		if(d==4){
			cout<<r-l<<endl;
		}	
	}
	return 0;
}

