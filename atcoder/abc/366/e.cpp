#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll l = -2.5e6, r = 2.5e6;
    auto f = [&](vector<ll> z) {
        vector<ll> ans(d + 1);
        ll sum = 0, diff = -n;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            sum += z[i] - l;
        }
        for (int i = l; i < r; i++) {
            if (sum <= d) ans[sum] += 1;
            while (ind != n && z[ind] == i) ind++, diff += 2;
            sum += diff;
        }
        return ans;
    };

    auto a = f(x);
    auto b = f(y);
    ll ans = 0, sum = 0;
    for (int i = 0; i <= d; i++) {
        sum += a[i];
        ans += sum * b[d - i];
    }
    cout << ans << endl;

    return 0;
}

