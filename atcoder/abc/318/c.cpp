#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, p;
    cin >> n >> d >> p;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    ranges::sort(f, greater<>());
    int i = 0;
    ll ans = 0;
    while (i < n) {
        ll tot = 0;
        int j = i;
        for (; j < d + i && j < n; j++) {
            tot += f[j];
        }
        i = j;
        if (tot > p) ans += p;
        else ans += tot;
    }
    cout << ans << endl;

    return 0;
}

