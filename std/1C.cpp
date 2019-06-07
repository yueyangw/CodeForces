#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
using namespace std;

const double PI = acos(-1);
typedef complex<double> Point;

Point ReadPoint() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return Point(x, y);
}

struct Solution {
    bool Round(double angle, int n) {
        double arc = angle / PI * n;
        return abs(arc - round(arc)) < 1e-4;
    }

    void Solve() {
        Point pointA = ReadPoint();
        Point pointB = ReadPoint();
        Point pointC = ReadPoint();
        Point vecAB = pointB - pointA;
        Point vecBC = pointC - pointB;
        Point vecCA = pointA - pointC;
        double angleA = fmod((arg(vecCA) - arg(vecAB) + PI * 2), PI);
        double angleB = fmod((arg(vecAB) - arg(vecBC) + PI * 2), PI);
        double sinA = sin(angleA);
        double dSquare = norm(vecBC) / (sinA * sinA);
        int n = 3;
        while (!Round(angleA, n) || !Round(angleB, n)) ++n;
        printf("%.8f\n", dSquare * sin(PI * 2 / n) * n * 0.125);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
