#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << "\n";
        return;
    }
    vector<int> d;
    for (int i = n; i > 0; i--) {
        d.push_back(i);
        if (i < n) d.push_back(i);
    }
    for (int i = 0, cnt = 0; i < d.size(); i++) {
        cnt += d[i];
        if (cnt >= k) {
            cout << i + 1 << "\n";
            return;
        }
    }
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

