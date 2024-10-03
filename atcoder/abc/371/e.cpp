#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> cnt(n + 1, {-1});
    for (int i = 0; i < n; i++) {
        cnt[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++) {
        cnt[i].push_back(n);
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += 1ll * n * (n + 1) / 2;
        for (int j = 1; j < cnt[i].size(); j++) {
            int k = cnt[i][j] - cnt[i][j - 1] - 1;
            ans -= 1ll * k * (k + 1) / 2;
        }
    }
    cout << ans << endl;

    return 0;
}

