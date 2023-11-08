#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    auto check = [&](ll x) {
        int i = 0, cnt = 0;
        ll t = x;
        for (; i < n; i++) {
            if (l[i] > x) return false;
            if (l[i] <= t) t -= l[i] + 1;
            else {
                cnt++;
                if (cnt == m) return false;
                t = x - l[i] - 1;
            }
        }
        return true;
    };

    ll lo = 1, hi = 1e16;
    while (lo < hi) {
        ll mid = lo + hi >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;

    return 0;
}

