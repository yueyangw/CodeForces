#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int xo[100009], a[100009];
ll ans[100009];
ll cnt[1 << 20];
ll res;
struct query{
	int x, y, list;
	int xk, yk;
}q[100009];

bool cmp(const query &a, const query &b){
	if(a.yk != b.yk) return a.yk < b.yk;
	if(a.yk % 2 == 1) return a.xk > b.xk;
	return a.xk < b.xk;
}

void add(int x){
	res += cnt[x ^ k];
	cnt[x]++;
}

void del(int x){
	cnt[x]--;
	res -= cnt[x ^ k];
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		xo[i] = xo[i - 1] ^ a[i];
	}
	int t = sqrt(n);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		q[i].x = x, q[i].y = y;
		q[i].list = i;
		q[i].xk = x / t;
		q[i].yk = y / t;
	}
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 1;
	add(xo[l]);
	for(int i = 1; i <= m; i++){
		int x = q[i].x, y = q[i].y;
		while(r < y){
			r++;
			add(xo[r]);
		}
		while(l < x){
			del(xo[l]);
			l++;
		}
		while(r > y){
			del(xo[r]);
			r--;
		}
		while(l > x){
			l--;
			add(xo[l]);
		}
		ans[q[i].list] = res;
	}
	for(int i = 1; i <= m; i++){
		printf("%lld\n", ans[i]);
	}
}
