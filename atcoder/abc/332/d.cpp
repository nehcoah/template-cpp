#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    int t[6] = {0, 0, 2, 6, 24, 120};
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    auto check = [&](auto &x, auto &y) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (x[i][j] != y[i][j]) return false;
            }
        }
        return true;
    };

    vector<int> order_h(h), order_w(w);
    iota(order_h.begin(), order_h.end(), 0);
    iota(order_w.begin(), order_w.end(), 0);
    auto build = [&]() {
        vector<vector<int>> cur(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cur[i][j] = a[order_h[i]][order_w[j]];
            }
        }
        return check(cur, b);
    };

    auto get = [&](auto x) {
        int q = 0;
        for (int i = 0; i < x.size(); i++) {
            for (int j = i + 1; j < x.size(); j++) {
                q += x[i] > x[j];
            }
        }
        return q;
    };

    int ans = 1e4;
    for (int i = 0; i < t[h]; i++) {
        for (int j = 0; j < t[w]; j++) {
            if (build()) ans = min(ans, get(order_h) + get(order_w));
            next_permutation(order_w.begin(), order_w.end());
        }
        next_permutation(order_h.begin(), order_h.end());
    }
    cout << (ans == 1e4 ? -1 : ans) << endl;

    return 0;
}

