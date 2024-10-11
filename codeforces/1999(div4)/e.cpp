#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

vector<int> p, sum;

void solve() {
    int l, r;
    cin >> l >> r;
    cout << sum[r + 1] - sum[l + 1] + 2 * p[l] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p.resize(2e5 + 1);
    sum.resize(2e5 + 2);
    p[0] = 0;
    for (int i = 1; i <= p.size(); i++) {
        p[i] = p[i / 3] + 1;
    }
    for (int i = 0; i < sum.size() - 1; i++) {
        sum[i + 1] = sum[i] + p[i];
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

