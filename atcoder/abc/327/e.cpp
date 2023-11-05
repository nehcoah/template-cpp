#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<double> f(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            f[j + 1] = max(f[j + 1], f[j] * 0.9 + p[i]);
        }
    }

    double ans = -1e12;
    double c = 0;
    for (int i = 1; i <= n; i++) {
        c = c * 0.9 + 1;
        ans = max(ans, f[i] / c - 1200 / sqrt(i));
    }
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}


// #include "bits/stdc++.h"

// using namespace std;
// using ll = long long;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> p(n);
//     for (int i = 0; i < n; i++) cin >> p[i];

//     vector<double> power(n + 2), sum(n + 2);
//     power[0] = power[1] = 1;
//     for (int i = 1; i < n + 2; i++) power[i] = 0.9 * power[i - 1];
//     for (int i = 1; i < n + 2; i++) sum[i] = sum[i - 1] + power[i];

//     vector f(n + 1, vector<double>(2, -1e18));
//     for (int i = n - 1; i >= 0; i--) {
//         vector tmp(n + 1, vector<double>(2, -1e18));
//         for (int j = 1; j <= n; j++) {
//             tmp[j][0] = max(f[j][0], f[j][1]);
//             tmp[j][1] = max(tmp[j][1], (max(f[j - 1][0], f[j - 1][1]) * sum[j - 1] + power[j] * p[i]) / sum[j]);
//         }
//         f = move(tmp);
//     }
//     double ans = -1e18;
//     for (int i = 1; i <= n; i++) ans = max(ans, max(f[i][0], f[i][1]) - 1200 / sqrt(i));
//     cout << fixed << setprecision(15) << ans << endl;

//     return 0;
// }

