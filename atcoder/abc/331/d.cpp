#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<string> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<ll>> sum(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (p[i][j] == 'B');
        }
    }

    function<ll(ll, ll)> get = [&](ll x, ll y) -> ll {
        if (x > n) {
            return get(x % n, y) + get(n, y) * (x / n);
        }
        if (y > n) {
            return get(x, y % n) + get(x, n) * (y / n);
        }
        return sum[x][y];
    };

    for (int i = 0; i < q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        c++, d++;
        cout << get(c, d) - get(c, b) - get(a, d) + get(a, b) << "\n";
    }

    return 0;
}


