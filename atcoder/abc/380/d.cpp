#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> len{(ll) s.size()};
    while (len.back() < 1e18) {
        len.push_back(len.back() * 2);
    }

    auto dfs = [&](auto self, ll k) -> pair<ll, int> {
        auto it = lower_bound(len.begin(), len.end(), k);
        if (it == len.begin()) {
            return {k, 1};
        }
        it = prev(it);
        auto [x, cnt] = self(self, k - *it);
        return {x, cnt + 1};
    };

    for (int i = 0; i < n; i++) {
        auto [k, cnt] = dfs(dfs, a[i]);
        if (cnt % 2 == 0) {
            cout << char(s[k - 1] ^ 32) << " \n"[i == n - 1];
        } else {
            cout << s[k - 1] << " \n"[i == n - 1];
        }
    }

    return 0;
}
