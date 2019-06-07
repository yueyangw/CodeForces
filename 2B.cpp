#include<bits/stdc++.h>
using namespace std;

int n;
bool flag;
int xq,yq;

int a[2009][2009],f[2009][2009];

int pd(int x,int k){
	if(x==0) return 0x3f3f3f3f;
	int ans=0;
	while(x%k==0){
		ans++;
		x/=k;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0) flag=1,xq=i,yq=j;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k=pd(a[i][j],2);
			if(j==1&&i==1){
				f[i][j]=k;
				continue;
			}
			f[i][j]=min(f[i-1][j],f[i][j-1])+k;
		}
	}
	string ans1,ans2;
	int x=n,y=n;
	while(x!=1||y!=1){
		if(f[x-1][y]<f[x][y-1]){
			x--;
			ans1+="D";
		}
		else{
			y--;
			ans1+="R";
		}
	}
	reverse(ans1.begin(),ans1.end());
	int answer=f[n][n];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k=pd(a[i][j],5);
			if(j==1&&i==1){
				f[i][j]=k;
				continue;
			}
			f[i][j]=min(f[i-1][j],f[i][j-1])+k;
		}
	}
	x=n,y=n;
	while(x!=1||y!=1){
		if(f[x-1][y]<f[x][y-1]){
			x--;
			ans2+="D";
		}
		else{
			y--;
			ans2+="R";
		}
	}
	reverse(ans2.begin(),ans2.end());
	if(min(f[n][n],answer)>1&&flag){
		printf("1\n");
		int xx=1,yy=1;
		while(xx<xq){
			xx++;
			printf("D");
		}
		while(yy<n){
			yy++;
			printf("R");
		}
		while(xx<n){
			xx++;
			printf("D");
		}
		cout<<endl;
		return 0;
	}
	if(f[n][n]<answer){
		cout<<f[n][n]<<endl<<ans2;
	}
	else{
		cout<<answer<<endl<<ans1;
	}
	cout<<endl;
	return 0;
}
