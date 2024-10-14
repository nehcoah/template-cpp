#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n + 2), y(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    for (int i = 0; i < n + 1; i++) {
        ans += sqrt(1ll * (x[i] - x[i + 1]) * (x[i] - x[i + 1]) + 1ll * (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

