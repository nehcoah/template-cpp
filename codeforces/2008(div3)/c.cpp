#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int l, r;
    cin >> l >> r;
    int cnt = 1, cur = l, add = 1;
    while (true) {
        cur += add++;
        if (cur > r) break;
        cnt += 1;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

