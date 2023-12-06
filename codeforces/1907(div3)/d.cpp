#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    auto check = [&](int x) {
        int cl = 0, cr = 0;
        for (int i = 0; i < n; i++) {
            cl = max(l[i], cl - x);
            cr = min(r[i], cr + x);
            if (cl > cr) return true;
        }
        return false;
    };
    int ans = *ranges::partition_point(ranges::iota_view(0, int(1e9) + 1), check);
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

