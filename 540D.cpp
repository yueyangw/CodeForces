#include<bits/stdc++.h>
using namespace std;

int r, m, k;
double f[109][109][109];

double dp(int a, int b, int c){
	if(f[a][b][c] != 0) return f[a][b][c];
	if(a > r || b > m || c > k) return 0;
	if(a == r && b == m && c == k) return 1;
	double v = 0;
	if(b != 0 || c != 0){
		double fz = (a + 1) * c * 1.0;
		double fm = (a + 1) * b + (a + 1) * c + b * c * 1.0;
		v += dp(a + 1, b, c) * (fz / fm);
	}
	if(a != 0 || c != 0){
		double fz = (b + 1) * a * 1.0;
		double fm = (b + 1) * a + a * c + (b + 1) * c * 1.0;
		v += dp(a, b + 1, c) * (fz / fm);
	}
	if(b != 0 || a != 0){
		double fz = (c + 1) * b * 1.0;
		double fm = a * b + a * (c + 1) + b * (c + 1) * 1.0;
		v += dp(a, b, c + 1) * (fz / fm);
	}
	f[a][b][c] = v;
	return v;
}

int main(){
	scanf("%d%d%d", &r, &m, &k);
	double a, b, c;
	for(int i = r; i > 0; i--) a += dp(i, 0, 0);
    for(int i = m; i > 0; i--) b += dp(0, i, 0);
    for(int i = k; i > 0; i--) c += dp(0, 0, i);
    printf("%.12lf %.12lf %.12f ", a, b, c);
	return 0;
}
