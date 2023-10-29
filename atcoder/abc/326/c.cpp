#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ranges::sort(a);
    int ans = 0;
    for (int l = 0, r = 0; r < n; l++) {
        while (r < n && a[r] < a[l] + m) r++;
        ans = max(ans, r - l);
    }
    cout << ans << endl;

    return 0;
}

