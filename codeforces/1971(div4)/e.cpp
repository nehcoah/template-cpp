#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> a[i + 1];
    }
    a.push_back(a.back() + 1);
    for (int i = 0; i < k; i++) {
        cin >> b[i + 1];
    }
    while (q--) {
        int d; cin >> d;
        int x = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
        assert(x != -1 && x + 1 <= a.size());
        cout << 1ll * b[x] + 1ll * (b[x + 1] - b[x]) * (d - a[x]) / (a[x + 1] - a[x]) << " \n"[q == 0];
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
