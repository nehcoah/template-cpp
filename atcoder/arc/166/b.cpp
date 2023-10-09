#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> std{a, b, c}, A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<ll> lcm(8, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if (j >> i & 1) lcm[j] = std::lcm(std[i], lcm[j]);
        }
    }

    vector<ll> f(8, 2e18);
    f[0] = 0;
    for (ll x : A) {
        auto tmp = f;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                ll cost = x % lcm[j];
                if (cost != 0) cost = lcm[j] - cost;
                tmp[i | j] = min(tmp[i | j], f[i] + cost);
            }
        }
        f = move(tmp);
    }

    cout << f.back() << endl;

    return 0;
}

