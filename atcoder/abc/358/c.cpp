#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = n + 1;
    for (int mask = 0; mask < 1 << n; mask++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == 'o') cur |= 1 << j;
                }
            }
        }
        if (cur == (1 << m) - 1) ans = min(ans, __builtin_popcount(mask));
    }
    cout << ans << endl;

    return 0;
}

