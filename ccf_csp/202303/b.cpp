#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> t(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }

    auto check = [&](int x) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] > x) sum += (ll)c[i] * (t[i] - x);
        }
        return sum > m;
    };

    int l = k, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;

    return 0;
}


