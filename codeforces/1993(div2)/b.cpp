#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> odd, even;
    for (int x : a) {
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    if (odd.empty() || even.empty()) {
        cout << 0 << "\n";
        return;
    }

    int ans = even.size();
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    ll cur = odd.back();
    for (int x : even) {
        if (cur < x) {
            ans += 1;
            break;
        }
        cur += x;
    }
    cout << ans << "\n";
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

