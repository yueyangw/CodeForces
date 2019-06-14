#include<bits/stdc++.h>
using namespace std;
typedef complex<double> Point;
const double PI = 3.1415926535;

Point ReadPoint() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return Point(x, y);
}

struct Solution{
	bool pd(double x, int n){
		x = n / PI * x;
		int z = x + 0.5;
		return abs(x - (double)z) < 1e-4;
	}
	
	void Solve(){
		Point pointA = ReadPoint();
        Point pointB = ReadPoint();
        Point pointC = ReadPoint();
		Point AB = pointB - pointA;
		Point BC = pointC - pointB;
		Point AC = pointC - pointA;
		double A = fmod((arg(-AC) - arg(AB) + PI * 2), PI);
        double B = fmod((arg(AB) - arg(BC) + PI * 2), PI);
        double R = abs(BC) / sin(A) / 2;
        int n = 3;
        while (!pd(A, n) || !pd(B, n)) ++n;
        double ans = 0.5 * R * R * sin(2 * PI / n) * n;
        printf("%.8f\n", ans);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
