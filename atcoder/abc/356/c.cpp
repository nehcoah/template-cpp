#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> mask(m), t(m);
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int x; cin >> x; x -= 1;
            mask[i] |= 1 << x;
        }
        char r; cin >> r;
        t[i] = r == 'o';
    }

    int ans = 0;
    for (int x = 0; x < 1 << n; x++) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if ((__builtin_popcount(x & mask[i]) >= k) != t[i]) ok = false;
        }
        ans += ok;
    }
    cout << ans << endl;

    return 0;
}

