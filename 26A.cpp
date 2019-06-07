#include<bits/stdc++.h>
using namespace std;

int n,a[3009],tot;
bool p[3009];
bool ans[90000009];

bool prime(int x){
	int flag=1;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}

void sf(){
	p[1]=1;
	for(int i=2;i<=n;i++){
		if(!prime(i)) continue;
		for(int j=i+i;j<=n;j+=i){
			p[j]=1;
		}
	}
}

int main(){
	scanf("%d",&n);
	sf();
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			a[++tot]=i;
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			if(i==j) continue;
			for(int k1=a[i];k1<=2*n;k1*=a[i]){
				for(int k2=a[j];k2<=2*n;k2*=a[j]){
					if(k1*k2>n) continue;
					ans[k1*k2]=1;
				}
			}
		}
	}
	int anss=0;
	for(int i=1;i<=n;i++){
		if(ans[i]) anss++;
	}
	cout<<anss;
	return 0;
}
