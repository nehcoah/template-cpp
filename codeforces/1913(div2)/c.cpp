#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(30);

    auto check = [&](int x) {
        vector<int> t(30);
        for (int i = 0; i < 30; i++) {
            if (x >> i & 1) t[i] = 1;
        }
        auto cur = cnt;
        for (int i = 0; i < 30; i++) {
            if (t[i]) {
                if (cur[i] == 0) return false;
                cur[i]--, t[i] = 0;
            }
            if (i < 29) cur[i + 1] += cur[i] / 2;
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cnt[x]++;
        } else {
            cout << (check(x) ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

