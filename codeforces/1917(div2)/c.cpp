#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    auto check = [&]() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i + 1) cnt++;
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < d && i < 2 * n; i++) {
        ans = max(ans, check() + (d - i - 1) / 2);
        for (int j = 0; j < b[i % k]; j++) {
            a[j] += 1;
        }
    }
    cout << ans << endl;
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

