#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int P = 1e9 + 7;
const int IT = 100000;
const double eps = 1e-9;

struct Circle {
    double x, y, r;
};

bool yep(double x, double y, const Circle &c) {
    double dx = x - c.x;
    double dy = y - c.y;
    return dx * dx + dy * dy - c.r * c.r <= eps;
}

double exact_area() {
    const double S =
            0.25 * M_PI + 1.25 * asin(0.8) - 1.0;
    return S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Circle c1{1.0, 1.0, 1.0};
    Circle c2{1.5, 2.0, sqrt(5) / 2.0};
    Circle c3{2.0, 1.5, sqrt(5) / 2.0};


    double x_min_wide = 0.0, x_min_narrow = 0.75;
    double x_max_wide = 3.0, x_max_narrow = 2.0;
    double y_min_wide = 0.0, y_min_narrow = 0.75;
    double y_max_wide = 3.0, y_max_narrow = 2.0;

    double w_wide = x_max_wide - x_min_wide, w_narrow = x_max_narrow - x_min_narrow;
    double h_wide = y_max_wide - y_min_wide, h_narrow = y_max_narrow - y_min_narrow;

    mt19937_64 rng(P);
    uniform_real_distribution<double> dist_x_wide(x_min_wide, x_max_wide);
    uniform_real_distribution<double> dist_y_wide(y_min_wide, y_max_wide);
    uniform_real_distribution<double> dist_x_narrow(x_min_narrow, x_max_narrow);
    uniform_real_distribution<double> dist_y_narrow(y_min_narrow, y_max_narrow);

    cout << "Count of all points,Count of points in wide area,Count of points in narrow area,"
            "Exact area,Wide area,Wide area error,Narrow area,Narrow area error\n";

    double exact = exact_area();

    for (int n = 100; n <= IT; n += 500) {
        double cnt_w = 0, cnt_n = 0;
        for (int i = 0; i < n; ++i) {
            double x_w = dist_x_wide(rng), x_n = dist_x_narrow(rng);
            double y_w = dist_y_wide(rng), y_n = dist_y_narrow(rng);
            if (yep(x_w, y_w, c1) && yep(x_w, y_w, c2) && yep(x_w, y_w, c3))
                cnt_w += 1;
            if (yep(x_n, y_n, c1) && yep(x_n, y_n, c2) && yep(x_n, y_n, c3))
                cnt_n += 1;
        }

        double wide_area = cnt_w / n * w_wide * h_wide;
        double narrow_area = cnt_n / n * w_narrow * h_narrow;
        double wide_error = fabs(wide_area - exact) / exact;
        double narrow_error = fabs(narrow_area - exact) / exact;

        cout << n << ',' << (int)cnt_w << ',' << (int)cnt_n << ',' << fixed << setprecision(10) <<
                exact << ',' << wide_area << ',' << wide_error << ',' << narrow_area << ',' << narrow_error << '\n';
    }
    return 0;
}
