#include<bits/stdc++.h>
using namespace std;
int n;
int num;
map<string,int>a;
int main(){
	scanf("%d",&n);
	while(n--){
		int x,y;
		string str;
		cin>>x;
		if(x==1){
			cin>>str>>y;
			if(!a[str])num++;
			a[str]=y;
			printf("OK\n");
		}
		if(x==2){
			cin>>str;
			if(!a[str])printf("Not found\n");
			else printf("%d\n",a[str]);
		}
		if(x==3){
			cin>>str;
			if(!a[str])printf("Not found\n");
			else {
				a[str]=0;
				num--;
				printf("Deleted successfully\n");
			}
		}
		if(x==4){
			printf("%d\n",num);
		}
	}

	return 0;
}

