#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long a[maxn],cnt;
string str; 
int k;
long long ans;
int main(){
	cin>>str;
	k=1;
	for(int i=1;i<str.size();i++){
		if(int(str[i-1])!=int(str[i])-1 && int(str[i-1])!=int(str[i]))a[++cnt]=k,k=1;
		else k++;
	}
	a[++cnt]=k;
	for(int i=1;i<=cnt;i++)ans=ans+((a[i]+1)*a[i])/2;
	for(int i=1;i<cnt;i++)ans=ans+a[i]*a[i+1];
	printf("%lld",ans);
	return 0;
}

