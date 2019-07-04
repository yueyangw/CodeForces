#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll v[100009];
ll addn[100009], ren[100009];
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
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(y == fa) continue;
		dfs(y, x);
		addn[x] = max(addn[x], addn[y]);
		ren[x] = max(ren[x], ren[y]);
	}
	v[x] += addn[x] - ren[x];
	if(v[x] > 0) ren[x] += v[x];
	else addn[x] -= v[x];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n - 1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
		if(v[i] > 0) ren[i] = v[i];
		else addn[i] = -v[i];
	}
	dfs(1, 0);
	printf("%lld\n", addn[1] + ren[1]);
	return 0;
}
