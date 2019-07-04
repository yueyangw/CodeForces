#include<bits/stdc++.h>
using namespace std;

int n, m;
struct Edge{
	int x, y, w;
	Edge(int x = 0, int y = 0, int w = 0){
		this->x = x, this->y = y, this->w = w;
	}
}e[300009];
int dp[300009], tmp[300009];

bool cmp(const Edge &a, const Edge &b){
	return a.w < b.w;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		e[i] = Edge(x, y, w);
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		int k = i + 1;
		while(e[i].w == e[k].w) k++;
		k--;
		for(int j = i; j <= k; j++){
			tmp[e[j].y] = max(tmp[e[j].y], dp[e[j].x] + 1);
		}
		for(int j = k; j >= i; j--){
			dp[e[j].y] = max(dp[e[j].y], tmp[e[j].y]);
			tmp[e[j].y] = 0;
		}
		i = k;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
