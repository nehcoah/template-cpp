#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    cin >> n >> k;

    auto check = [&](ll x) {
        ll mid = k + x;
        return abs(1ll * (k + mid) * (x + 1) / 2 - 1ll * (mid + 1 + k + n - 1) * (n - 1 - x) / 2);
    };

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        ll a = check(max(0, mid - 1)), b = check(mid), c = check(min(n - 1, mid + 1));
        if (a == b && b == c) l += 1;
        else if (a <= b && b <= c) r = mid;
        else if (a >= b && b >= c) l = mid + 1;
        else l = mid, r = mid;
    }
    cout << check(l) << "\n";
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

