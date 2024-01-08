#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x[i] = n - i;
    }
    for (int i = 0; i < q; i++) {
        int o; cin >> o;
        if (o == 1) {
            char c; cin >> c;
            if (c == 'R') x.push_back(x.back() + 1), y.push_back(y.back());
            else if (c == 'L') x.push_back(x.back() - 1), y.push_back(y.back());
            else if (c == 'U') x.push_back(x.back()), y.push_back(y.back() + 1);
            else x.push_back(x.back()), y.push_back(y.back() - 1);
        } else {
            int p; cin >> p;
            cout << x[x.size() - p] << " " << y[y.size() - p] << "\n";
        }
    }

    return 0;
}

