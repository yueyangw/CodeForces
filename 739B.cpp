#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int n;
int64 a[200009];
struct Edge{
	int to, nxt;
	int64 w;
}e[400009];
int head[200009], tot;
int dep[200009], lca[200009][25];
int64 dis[200009];
int ans[200009];

void add(int x, int y, int w){
	e[++tot].to = y;
	e[tot].w = w;
	e[tot].nxt = head[x];
	head[x] = tot;
}

void dfs(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		dis[y] = dis[x] + e[i].w;
		lca[y][0] = x;
		dfs(y, x);
	}
}

void init_lca(){
	for(int i = 1; i < 20; i++){
		for(int j = 1; j <= n; j++){
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
		}
	}
}

int up(int x){
	int cs = x;
	for(int i = 19; i >= 0; i--){
		if(dis[cs] - dis[lca[x][i]] <= a[cs]){
			x = lca[x][i];
		}
	}
	return lca[x][0];
}

void dfs2(int x, int fa){
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		int ffa = up(y);
		ans[x]++;
		ans[ffa]--;
		dfs2(y, x);
	}
}

void dfs3(int x, int fa){
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		dfs3(y, x);
		ans[x] += ans[y];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i < n; i++){
		int p, w;
		scanf("%d%d", &p, &w);
		add(p, i + 1, w);
		add(i + 1, p, w);
	}
//	printf("79 Line\n");
	dfs(1, 0);
//	printf("81 Line\n");
	init_lca();
//	printf("83 Line\n");
	dfs2(1, 0);
//	printf("85 Line\n");
	dfs3(1, 0);
//	printf("87 Line\n");
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
