#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(30);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 25; i >= 0; i--) {
        ll x = 1ll * (h >> i) * (w >> i);
        if (x < a[i]) {
            cout << "No\n";
            return 0;
        }
        if (i > 0) a[i - 1] += 4 * a[i];
    }
    cout << "Yes\n";
    return 0;
}

