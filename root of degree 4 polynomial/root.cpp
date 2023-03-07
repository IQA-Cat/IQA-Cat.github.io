#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

// 定义复数类型
typedef complex<double> cpx;

// 计算平方根
cpx sqrt(double x) {
    return cpx(sqrt(x), 0);
}

// 计算四次方程的解
int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    // 计算 p 和 q
    double p = (8 * a * c - 3 * b * b) / (8 * a * a);
    double q = (b * b * b - 4 * a * b * c + 8 * a * a * d) / (8 * a * a * a);

    // 计算复数解
    cpx r = sqrt(p * p / 4 + q * q / 27);
    cpx u = pow(-q / 2 + r, 1.0 / 3);
    cpx v = pow(-q / 2 - r, 1.0 / 3);
    cpx x1 = (u + v) - b / (4 * a);

    // 输出复数解
    cout << "x1 = " << x1 << endl;

    return 0;
}
