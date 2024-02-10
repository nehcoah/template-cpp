#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    map<ll, ll> mp;
    auto dfs = [&](auto self, ll x) -> ll {
        if (x == 1) return 0;
        if (mp.contains(x)) return mp[x];
        ll t = x / 2;
        return mp[x] = self(self, t) + self(self, x - t) + x;
    };
    cout << dfs(dfs, n) << endl;

    return 0;
}
