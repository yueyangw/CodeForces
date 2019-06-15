#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Solution{
	const ll Mod = 1000000007;
	int n, a, b, k;
	vector<vector<ll> > g;
	
	void Solve(){
		scanf("%d%d%d%d", &n, &a, &b, &k);
		g.resize(n + 1);
		for(int i = 0; i <= n; i++){
			g[i].resize(k + 1);
			g[i][0] = 1;
		}
		g[b][0] = 0;
		for(int i = 1; i <= n; ++i){
			g[i][0] += g[i-1][0];
		}
		for(int i = 1; i <= k; ++i){
			for(int j = 1; j <= n; j++){
				int d1 = min(j + abs(j - b) - 1, n);
				int d2 = max(j - abs(j - b), 0);
				ll x1 = (g[d1][i - 1] + Mod - g[d2][i - 1]) % Mod;
				ll x2 = (g[j - 1][i - 1] + Mod - g[j][i - 1]) % Mod;
				g[j][i] = (g[j - 1][i] + (x1 + x2) % Mod) % Mod;
			}
		}
		printf("%lld\n", (g[a][k] + Mod - g[a - 1][k]) % Mod);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
