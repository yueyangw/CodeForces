#include<bits/stdc++.h>
using namespace std;

int n, m;
int dep[100009], lca[100009][25];
int d[100009];
struct edge{
	int x, y;
}a[100009];
struct Edge{
	int to, nxt;
}e[200009];
int head[100009], tot;

void add(int x, int y){
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

void dfs(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
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

int glca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--){
		if(dep[lca[x][i]] >= dep[y]){
			x = lca[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--){
		if(lca[x][i] != lca[y][i]){
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}

void dfs2(int x, int fa){
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		dfs2(y, x);
		d[x] += d[y];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n - 1; i++){
		scanf("%d%d", &a[i].x, &a[i].y);
		add(a[i].x, a[i].y);
		add(a[i].y, a[i].x);
	}
	dfs(1, 0);
	init_lca();
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		int lcaab = glca(x, y);
		d[x]++, d[y]++;
		d[lcaab] -= 2;
	}
	dfs2(1, 0);
	for(int i = 1; i <= n - 1; i++){
		int x = a[i].x, y = a[i].y;
		if(dep[x] < dep[y]) swap(x, y);
		printf("%d ", d[x]);
	}
	return 0;
}
