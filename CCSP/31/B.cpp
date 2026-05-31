#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long double> pre_c(n + 1, 1.0L);
    vector<long double> pre_j(n + 1, 0.0L);
    for (int i = 1; i <= n; ++i) {
        int a; long double b;
        scanf("%d %Lf", &a, &b);
        if (a == 1) {
            pre_c[i] = pre_c[i - 1] * b;
            pre_j[i] = pre_j[i - 1];
        } else if (a == 2) {
            pre_j[i] = pre_j[i - 1] + b;
            pre_c[i] = pre_c[i - 1];
        }
    }

    while (m--) {
        int l, r, X, Y;
        scanf("%d %d %d %d", &l, &r, &X, &Y);
        long double k = pre_c[r] / pre_c[l - 1];
        long double p = pre_j[r] - pre_j[l - 1];
        long double x = k * X;
        long double y = k * Y;
        long double ansX = x * cosl(p) - y * sinl(p);
        long double ansY = x * sinl(p) + y * cosl(p);
        printf("%.3Lf %.3Lf\n", ansX, ansY);
    }
    return 0;
}