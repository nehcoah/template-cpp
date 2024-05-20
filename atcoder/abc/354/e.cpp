#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> f(1 << n);
    for (int mask = 1; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mask >> i & 1 && mask >> j & 1) {
                    if (a[i] == a[j] || b[i] == b[j]) {
                        if (!f[mask ^ (1 << i) ^ (1 << j)]) {
                            f[mask] = true;
                        }
                    }
                }
            }
        }
    }
    cout << (f[(1 << n) - 1] ? "Takahashi" : "Aoki") << endl;

    return 0;
}
