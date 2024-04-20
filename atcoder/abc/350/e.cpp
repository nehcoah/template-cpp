//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    ll n, a, x, y;
    cin >> n >> a >> x >> y;

    map<ll, double> mp;
    auto dfs = [&](auto self, ll t) -> double {
        if (t == 0) return 0;
        if (mp.count(t)) return mp[t];
        double ans1 = self(self, t / a) + x;
        double ans2 = 0;
        for (int i = 2; i <= 6; i++) {
            ans2 += self(self, t / i) / 6;
        }
        ans2 = (ans2 + y) * 6 / 5;
        return mp[t] = min(ans1, ans2);
    };
    cout << dfs(dfs, n) << endl;

    return 0;
}
