#include<bits/stdc++.h>
using namespace std;

int n, m, d;
int a[100009];
int dep[4][100009];
bool vis[100009];

struct Edge{
	int to, nxt;
}e[200009];
int head[100009], tot;

void add(int x, int y){
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

void dfs(int x, int fa, int type){
	dep[type][x] = dep[type][fa] + 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		dfs(y, x, type);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n - 1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0, 1);
	int x = 1;
	for(int i = 1; i <= m; i++){
		if(dep[1][a[i]] > dep[1][a[x]])
			x = i;
	}
	x = a[x];
	dfs(x, 0, 2);
	for(int i = 1; i <= n; i++){
		if(dep[2][a[i]] > dep[2][a[x]])
			x = i;
	}
	x = a[x];
	dfs(x, 0, 3);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dep[2][i] - 1 <= d && dep[3][i] - 1 <= d){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
