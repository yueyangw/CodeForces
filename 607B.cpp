#include<bits/stdc++.h>
using namespace std;

struct Solution{
	int n,ans,start,end;
	vector<int> a;
	vector<vector<int> > f;
	
	int tj(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++) f[i][i]=1;
		for(int step=2;step<=(end-start+1);step++){
			for(int i=start;i+step-1<=end;i++){
				int j=i+step-1;
				if(j-i==1){
					f[i][j] = a[i]==a[j]?1:2;
					continue;
				}
				if(a[i]==a[j]){
					f[i][j]=f[i+1][j-1];
				}
				for(int k=i;k<j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
					
				}
				//printf("%d~%d : %d\n",i,j,f[i][j]);
			}
		}
		return f[start][end];
	}
	
	void Solve(){
		scanf("%d",&n);
		a.resize(n+1);
		f.resize(n+1);
		for(int i=0;i<=n;i++) f[i].resize(n+1);
		start=1,end=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=tj();
		printf("%d\n",ans);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
