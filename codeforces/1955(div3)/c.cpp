// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    deque<ll> dq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        dq.push_back(a);
    }
//    if (accumulate(dq.begin(), dq.end(), 0ll) <= k) {
//        cout << n << endl;
//        return;
//    }
    int ans = 0;
    while (k && !dq.empty()) {
        if (dq.size() == 1) {
            if (dq[0] <= k) ans += 1;
            break;
        }
        ll x = min({dq.front(), dq.back(), k});
        if (k <= 2 * x) {
            dq.front() -= k / 2;
            dq.back() -= k / 2;
            if (k % 2) dq.front() -= 1;
            k = 0;
        } else {
            dq.front() -= x;
            dq.back() -= x;
            k -= 2 * x;
        }
        if (dq.front() == 0) {
            dq.pop_front();
            ans += 1;
        }
        if (!dq.empty() && dq.back() == 0) {
            dq.pop_back();
            ans += 1;
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
