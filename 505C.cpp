#include<bits/stdc++.h>
using namespace std;

int D=500;
int n,d;
int a[30009],p[30009],f[30009][609];

int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		a[p[i]]++;
	}
	for(int i=0;i<=30000;i++){
		for(int j=-D;j<=D;j++){
			f[i][j+D]=-236245346;
		}
	}
	f[d][D]=a[0]+a[d];
	for(int i=d;i<=30000;i++){
		for(int j=-D;j<=D;j++){
			if(f[i][j+D]==-236245346) continue;
			for(int k=-1;k<=1;k++){
				int dd=j+d+k;
				if(j+k+D<0||j+k-D>0||dd<1||i+dd>30000) continue;
				f[i+dd][j+D+k]=max(f[i+dd][j+D+k],f[i][j+D]+a[i+dd]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=30000;i++){
		for(int j=-D;j<=D;j++){
			ans=max(ans,f[i][j+D]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
