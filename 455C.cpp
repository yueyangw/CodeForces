#include<bits/stdc++.h>
using namespace std;

int n, m, q;
const int MAXN = 3e5 + 9;
int fa[MAXN], dis[MAXN], ans, st;
bool vis[MAXN];

struct Edge{
	int nxt, to;
}e[2 * MAXN];
int head[MAXN], tot;

void add(int x, int y){
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

bool merge(int x, int y){
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	fa[yy] = xx;
	return true;
}

void dfs(int x, int v){
	if(v > ans) ans = v, st = x;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(vis[y]) continue;
		vis[y] = 1;
		dfs(y, v + 1);
	}
	vis[x] = 0;
}

void dfs2(int x, int v){
	if(v > ans) ans = v;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(vis[y]) continue;
		vis[y] = 1;
		dfs(y, v + 1);
	}
	vis[x] = 0;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
		merge(x, y);
	}
	for(int i = 1; i <= n; ++i){
		int x = find(i);
		if(dis[x]) continue;
		ans = -1;
		vis[x] = 1;
		dfs(x, 0);
		vis[st] = 1;
		dfs2(st, 0);
		dis[x] = ans;
	}
	for(int i = 1; i <= q; ++i){
		int op, x, y;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &x);
			printf("%d\n", dis[find(x)]);
		}
		else{
			scanf("%d%d", &x, &y);
			int xx = find(x), yy = find(y);
			if(xx == yy) continue;
			fa[xx] = yy;
			dis[yy] = max((dis[yy] + 1) / 2 + (dis[xx] + 1) / 2 + 1, max(dis[xx], dis[yy]));
		}
	}
	return 0;
}
