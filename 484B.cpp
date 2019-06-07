#include<bits/stdc++.h>
using namespace std;

bool cmp(const int& a,const int& b){
	return a>b;
}

struct Solution{
	int n,ans,maxn,q;
	vector<int> a;
	
	void Solve(){
		scanf("%d",&n);
		a.resize(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
		}
		sort(a.begin(),a.end());
		n=unique(a.begin(),a.end())-a.begin();
		a.resize(n);
		for(int i=0;i<n;i++){
			int k=2*a[i];
			while(k<maxn+a[i]){
				int x=lower_bound(a.begin(),a.end(),k)-a.begin()-1;
				if(x==-1){
					k+=a[i];
					continue;
				}
				//printf("k=%d a[%d]=%d a[x] mod a[i]=%d\n",k,x,a[x],a[x]%a[i]);
				ans=max(ans,a[x]%a[i]);
				k+=a[i];
			}
		}
		printf("%d\n",ans);
	}
	
};

int main(){
	Solution().Solve();
	return 0;
}
