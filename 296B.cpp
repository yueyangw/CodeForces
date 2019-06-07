#include<bits/stdc++.h>
using namespace std;

struct Solution{
	int n,m;
	vector<int> a,f;
	
	void Solve(){
		scanf("%d%d",&n,&m);
		a.resize(n+1);
		f.resize(n+1);
		for(int i=1;i<=n;i++){
			scanf("%d%*f",&a[i]);
		}
		for(int i=1;i<=n;i++) f[i]=0x3f3f3f3f;
		f[0]=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int x=upper_bound(f.begin(),f.end(),a[i])-f.begin();
			f[x]=a[i];
			//printf("%d %d %d\n",x,a[i],f[x]);
		}
		int ans=lower_bound(f.begin(),f.end(),0x3f3f3f3f)-f.begin()-1;
		printf("%d\n",n-ans);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
