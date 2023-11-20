#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<double> k{1.}, t{0.};
    for (int i = 0; i < n; i++) {
        int o;
        double x;
        cin >> o >> x;
        if (o == 1) {
            k.push_back(k.back() * x);
            t.push_back(t.back());
        } else {
            k.push_back(k.back());
            t.push_back(t.back() + x);
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < m; i++) {
        int l, r;
        double x, y, nx, ny;
        cin >> l >> r >> x >> y;
        double scale = k[r] / k[l - 1], circle = t[r] - t[l - 1];
        x *= scale;
        y *= scale;
        nx = x * cos(circle) - y * sin(circle);
        ny = x * sin(circle) + y * cos(circle);
        cout << nx << " " << ny << "\n";
    }

    return 0;
}


