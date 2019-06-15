#include<bits/stdc++.h>
using namespace std;

struct Solution {
	int n,D;
	vector<int> a;
	vector<vector<int> > f;
	
	int dfs(int s, int d) {
		if(s > 30000) return 0;
		if(f[d].size() == 0) {
			f[d].resize(30001);
			for(int i = 0; i <= 30000; ++i) {
				f[d][i] = -1;
			}
		}
		int ans = 0;
		if(f[d][s] != -1) return f[d][s];
		for(int t = -1; t <= 1; t++){
			if(d + t <= 0) continue;
			ans = max(ans, dfs(s + d, d + t));
		}
		return f[d][s] = ans + a[s];
	}
	
	void Solve() {
		scanf("%d%d", &n, &D);
		f.resize(30001);
		a.resize(30001);
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			++a[x];
		}
		printf("%d\n", dfs(0, D));
	}
};

int main(){
	Solution().Solve();
	return 0;
}
