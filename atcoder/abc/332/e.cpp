#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> w(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    double avg = (double) sum / d;
    vector<double> cost(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) cur += w[i];
        }
        cost[mask] = (cur - avg) * (cur - avg);
    }

    vector<double> f(1 << n, numeric_limits<double>::max());
    f[0] = 0;
    for (int i = 0; i < d; i++) {
        vector<double> tmp(1 << n, numeric_limits<double>::max());
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int sub = mask; ; sub = (sub - 1) & mask) {
                tmp[mask] = min(tmp[mask], f[sub] + cost[sub ^ mask]);
                if (sub == 0) break;
            }
        }
        f.swap(tmp);
    }
    cout << fixed << setprecision(16) << f[(1 << n) - 1] / d << endl;

    return 0;
}

