#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ranges::sort(x);
    ranges::sort(y);
    vector<ll> sumx(n + 1), sumy(n + 1);
    for (int i = 0; i < n; i++) sumx[i + 1] = sumx[i] + x[i];
    for (int i = 0; i < n; i++) sumy[i + 1] = sumy[i] + y[i];

    auto check = [&](vector<ll> &s, vector<ll> &sums, ll t) {
        ll ans = numeric_limits<ll>::max();
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && s[j] <= s[i] + t) j++;
            ans = min(ans, s[i] * i - sums[i] + sums[n] - sums[j] - (s[i] + t) * (n - j));
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (s[j] < s[i] - t) j++;
            ans = min(ans, (s[i] - t) * j - sums[j] + sums[n] - sums[i + 1] - s[i] * (n - i - 1));
        }
        return ans;
    };

    ll l = 0, r = 1e9 + 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(x, sumx, mid) + check(y, sumy, mid) <= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;

    return 0;
}


