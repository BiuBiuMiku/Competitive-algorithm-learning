#include<bits/stdc++.h>
using namespace std;
int n;
const int base1=233,base2=131;
const int mod1=19260817,mod2=1e9+5;
struct ha{
	int hash1,hash2; 
}a[10005]; 
int answer=0;
int gethash1(string str){
	unsigned long long up=0;
	for(int i=0;i<str.size();i++)
		up=(up*base1+str[i])%mod1;
	return up;
} 
int gethash2(string str){
	unsigned long long up=0;
	for(int i=0;i<str.size();i++)
		up=(up*base2+str[i])%mod2;
	return up;
} 
bool cmp(ha x,ha y){
	return x.hash1>y.hash1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string st;
		cin>>st;
		a[i].hash1=gethash1(st);
		a[i].hash2=gethash2(st);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].hash1!=a[i-1].hash1 || a[i].hash2!=a[i-1].hash2)
			answer++;
	printf("%d",answer); 
	return 0;
}

