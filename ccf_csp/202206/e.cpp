// 70

#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int n, q;
    cin >> n >> q;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int l, r;
            double a, b;
            cin >> l >> r >> a >> b;
            for (int j = l; j <= r; j++) {
                x[j] += a;
                y[j] += b;
            }
        } else if (o == 2) {
            int l, r;
            double a, b, th;
            cin >> l >> r >> a >> b >> th;
            for (int j = l; j <= r; j++) {
                x[j] -= a; y[j] -= b;
                double cx = x[j] * cos(th) - y[j] * sin(th);
                double cy = x[j] * sin(th) + y[j] * cos(th);
                x[j] = cx + a;
                y[j] = cy + b;
            }
        } else if (o == 3) {
            int l, r;
            double a, b, lambda;
            cin >> l >> r >> a >> b >> lambda;
            for (int j = l; j <= r; j++) {
                double dx = a - x[j], dy = b - y[j];
                dx *= lambda, dy *= lambda;
                x[j] = a - dx, y[j] = b - dy;
            }
        } else if (o == 4) {
            int l, r;
            double th, y0;
            cin >> l >> r >> th >> y0;
            double k = tan(th);
            for (int j = l; j <= r; j++) {
                double inter_x = (x[j] / k + y[j] - y0) / (k + 1 / k);
                x[j] += (inter_x - x[j]) * 2;
                double inter_y = k * inter_x + y0;
                y[j] += (inter_y - y[j]) * 2;
            }
        } else if (o == 5) {
            int l, r;
            double th, y0;
            cin >> l >> r >> th >> y0;
            double k = tan(th);
            for (int j = l; j <= r; j++) {
                x[j] = (x[j] / k + y[j] - y0) / (k + 1 / k);
                y[j] = k * x[j] + y0;
            }
        } else if (o == 6) {
            int l, r;
            cin >> l >> r;
            double tx = 0, ty = 0;
            for (int j = l; j <= r; j++) {
                tx += x[j], ty += y[j];
            }
            cout << tx / (r - l + 1) << " " << ty / (r - l + 1) << "\n";
        } else {
            int l, r;
            double a, b;
            cin >> l >> r >> a >> b;
            double ans = 0;
            for (int j = l; j <= r; j++) {
                ans += (a - x[j]) * (a - x[j]) + (b - y[j]) * (b - y[j]);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}


