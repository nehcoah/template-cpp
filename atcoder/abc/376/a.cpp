#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1, p = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - p >= c) {
            ans += 1, p = a[i];
        }
    }
    cout << ans << endl;

    return 0;
}

