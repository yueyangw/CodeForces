#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int data,pos;
};

bool cmp(const node &a, const node &b){
	return a.data < b.data;
}

struct Solution{
	int n;
	vector<int> a, p;
	vector<node> keyv;
	vector<ll> d, ansl, ansr;
	
	int lowbit(int x){return x & -x;}
	
	void update(int x) {
		while(x <= n) {
			d[x]++;
			x += lowbit(x);
		}
	}
	
	ll gsum(int x) {
		ll sum = 0;
		while(x) {
			sum += d[x];
			x -= lowbit(x);
		}
		return sum;
	}
	
	void Solve(){
		scanf("%d", &n);
		a.resize(n + 1);
		keyv.resize(n + 1);
		p.resize(n + 1);
		ansl.resize(n + 1);
		ansr.resize(n + 1);
		d.resize(n + 1);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			keyv[i].data = a[i];
			keyv[i].pos = i;
		}
		sort(keyv.begin() + 1, keyv.end(), cmp);
		int id = 1;
		p[keyv[1].pos] = 1;
		for(int i = 2; i <= n; i++) {
			if(keyv[i].data == keyv[i - 1].data) {
				p[keyv[i].pos] = id;
			}
			else {
				p[keyv[i].pos] = ++id;
			}
		}
		for(int i = 1; i <= id; i++) {
			update(p[i]);
			ansl[i] = i - gsum(p[i]);
		}
		reverse(p.begin() + 1, p.end());
		d = vector<ll> (n + 1);
		for(int i = 1; i <= n; i++) {
			d[i] = 0;
			p[i] = id + 1 - p[i];
		}
		for(int i = 1; i <= n; i++) {
			update(p[i]);
			ansr[i] = i - gsum(p[i]);
		}
		reverse(ansr.begin() + 1, ansr.end());
		ll ans = 0;
		for(int i = 1; i <= n; i++) ans += ansl[i] * ansr[i];
		printf("%lld\n", ans);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
