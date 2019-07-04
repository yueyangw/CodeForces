#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100009;

int n, m;
ll ans, power[25];
int tree[N * 4][25], tag[N * 4][25], v[N * 4];

void build(int k, int l, int r){
	if(l == r){
		int c = v[l];
		for(int i = 0; i <= 20; i++){
			if((c >> i) & 1) tree[k][i] = 1; 
		}
		return;
	}
	int mid = (l + r) / 2;
	build(k * 2, l, mid);
	build(k * 2 + 1, mid + 1, r);
	for(int i = 0; i <= 20; i++){
		tree[k][i] = tree[k * 2][i] + tree[k * 2 + 1][i];
	}
}

void pushdown(int k, int l, int r, int p){
	tree[k][p] = (r - l + 1) - tree[k][p];
	if(l != r){
		tag[k * 2][p] ^= 1;
		tag[k * 2 + 1][p] ^= 1;
		tag[k][p] = 0;
	}
	tag[k][p] = 0;
}

void modify(int k, int l, int r, int x, int y, int p){
	if(tag[k][p]) pushdown(k, l, r, p);
	if(l > y || r < x) return;
	if(l >= x && r <= y){
		pushdown(k, l, r, p);
		return;
	}
	int mid = (l + r) / 2;
	modify(k * 2, l, mid, x, y, p);
	modify(k * 2 + 1, mid + 1, r, x, y, p);
	tree[k][p] = tree[k * 2][p] + tree[k * 2 + 1][p];
}

void query(int k, int l, int r, int x, int y){
	for(int i = 0; i <= 20; i++)
		if(tag[k][i]) pushdown(k, l, r, i);
	if(l >= x && r <= y){
		for(int i = 0; i <= 20; i++)
			ans += tree[k][i] * power[i];
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= x) query(k * 2, l, mid, x, y);
	if(mid < y) query(k * 2 + 1, mid + 1, r, x, y);
}

int main(){
	power[0] = 1;
	for(int i = 1; i <= 21; i++) power[i] = power[i - 1] << 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int op, x, y, w;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1){
			ans = 0;
			query(1, 1, n, x, y);
			printf("%lld\n", ans);
		}
		else{
			scanf("%d", &w);
			for(int i = 0; i <= 20; i++){
				if((w >> i) & 1) modify(1, 1, n, x, y, i);
			}
		}
	}
	return 0;
}
