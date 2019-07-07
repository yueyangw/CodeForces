#include<bits/stdc++.h>
using namespace std;

int n, m;
struct Edge{
	int to, nxt;
}e[200009];
int head[100009], tot;
int lca[100009][25], dep[100009], size[100009];

void add(int x, int y){
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

void dfs(int x, int fa){
	size[x] = 1;
	dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		lca[y][0] = x;
		dfs(y, x);
		size[x] += size[y];
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

int up(int x, int k){
	int p = 0;
	while(k){
		if(k & 1) x = lca[x][p];
		p++;
		k >>= 1;
	}
	return x;
}

int solve(int x, int a, int b){
	int ans = 1;
	int lcaab = glca(a, b);
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(glca(y, a) == y && glca(y, b) == lcaab) continue;
		if(glca(y, a) == lcaab && glca(y, b) == y) continue;
		if(dep[y] > dep[x]){
			ans += size[y];
		}
		else{
			ans += size[y] - size[x]; 
		}
	}
	return ans;
}

int solve2(int x, int y){
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
	return n - size[x] - size[y];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	init_lca();
	size[0] = size[1];
	scanf("%d", &m);
	for(int qwq = 1; qwq <= m; qwq++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == y){
			printf("%d\n", n);
			continue;
		}
		int lcaxy = glca(x, y);
		if((dep[x] + dep[y] - 2 * dep[lcaxy]) % 2 == 1){
			printf("0\n");
			continue;
		}
		else{
			int l = dep[x] - dep[lcaxy];
			int r = dep[y] - dep[lcaxy];
			if(l == r){
				int ans = solve2(x, y);
				printf("%d\n", ans);
			}
			else{
				if(l < r){
					swap(l, r);
					swap(x, y);
				}
				int to = x;
				for(int i = 19; i >= 0; i--){
					if(dep[x] - dep[lca[to][i]] < ((l + r) / 2)){
						to = lca[to][i];
					}
				}
				int mid = lca[to][0];
				int ans = size[mid] - size[to];
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
