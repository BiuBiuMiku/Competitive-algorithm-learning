#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6+5;
long long T;
long long n,r;
unsigned long long a[maxn];
unsigned long long num;
signed main(){
	scanf("%lld",&T);
	while(T--){
		r=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			string str;
			cin>>str;
			if(str=="push"){
				cin>>num;
				a[++r]=num;
			}
			if(str=="query"){
				if(r==0)printf("Anguei!\n");
				else cout<<a[r]<<endl;
			}
			if(str=="pop"){
				if(r==0)printf("Empty\n");
				else r--;
			}
			if(str=="size"){
				cout<<r<<endl;
			}
		}	
	}
	return 0;
}

