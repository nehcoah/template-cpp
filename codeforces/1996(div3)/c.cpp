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

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<array<int, 26>> suma(n + 1), sumb(n + 1);
    for (int i = 0; i < n; i++) {
        suma[i + 1] = suma[i];
        sumb[i + 1] = sumb[i];
        suma[i + 1][a[i] - 'a'] = suma[i][a[i] - 'a'] + 1;
        sumb[i + 1][b[i] - 'a'] = sumb[i][b[i] - 'a'] + 1;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto A = suma[r] - suma[l - 1];
        auto B = sumb[r] - sumb[l - 1];
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += max(0, A[i] - B[i]);
        }
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

