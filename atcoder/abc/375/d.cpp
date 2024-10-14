#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

array<int, 26> operator-(const array<int, 26> &a, const array<int, 26> &b) {
    array<int, 26> c{};
    for (int i = 0; i < 26; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<array<int, 26>> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i];
        sum[i + 1][s[i] - 'A'] += 1;
    }

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        auto pre = sum[i];
        auto suf = sum.back() - sum[i + 1];
        for (int x = 0; x < 26; x++) {
            ans += 1ll * pre[x] * suf[x];
        }
    }
    cout << ans << endl;

    return 0;
}

