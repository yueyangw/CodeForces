#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int N = 200009;
const int64 MAXN = 0x7f7f7f7f7f7f7f7f;

int n, m;
int64 tree[N * 4], tag[N * 4];
int64 v[N];

void build(int k, int l, int r){
	if(l == r){
		tree[k] = v[l];
		return;
	}
	int mid = (l + r) / 2;
	build(k * 2, l, mid);
	build(k * 2 + 1, mid + 1, r);
	tree[k] = min(tree[k * 2], tree[k * 2 + 1]);
}

void modify(int k, int l, int r, int x, int y, int val){
	if(l >= x && r <= y){
		tag[k] += val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= x) modify(k * 2, l, mid, x, y, val);
	if(mid < y) modify(k * 2 + 1, mid + 1, r, x, y, val);
	tree[k] = min(tree[k * 2] + tag[k * 2], tree[k * 2 + 1] + tag[k * 2 + 1]);
}

int64 query(int k, int l, int r, int x, int y){
	if(l >= x && r <= y){
		return tree[k] + tag[k];
	}
	int mid = (l + r) / 2;
	int64 left = MAXN, right = MAXN;
	if(mid >= x) left = query(k * 2, l, mid, x, y);
	if(mid < y) right = query(k * 2 + 1, mid + 1, r, x, y);
	return min(left, right) + tag[k];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		int64 val;
		scanf("%d%d", &x, &y);
		x++, y++;
		char op;
		op = getchar();
		if(op == '\n'){
			if(x <= y){
				printf("%lld\n", query(1, 1, n, x, y));
			}
			else{
				int64 ans;
				ans = query(1, 1, n, 1, y);
				ans = min(ans, query(1, 1, n, x, n));
				printf("%lld\n", ans);
			}
		}
		else{
			scanf("%lld", &val);
			if(x <= y){
				modify(1, 1, n, x, y, val);
			}
			else{
				modify(1, 1, n, x, n, val);
				modify(1, 1, n, 1, y, val);
			}
		}
	}
	return 0;
}
