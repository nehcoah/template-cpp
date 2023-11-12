#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, ans = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c <= x) ans += c;
    }
    cout << ans << endl;

    return 0;
}

