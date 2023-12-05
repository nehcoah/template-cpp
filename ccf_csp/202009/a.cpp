#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        int da = (p[a].first - x) * (p[a].first - x) + (p[a].second - y) * (p[a].second - y);
        int db = (p[b].first - x) * (p[b].first - x) + (p[b].second - y) * (p[b].second - y);
        return da == db ? a < b : da < db;
    });
    cout << idx[0] + 1 << "\n";
    cout << idx[1] + 1 << "\n";
    cout << idx[2] + 1 << "\n";

    return 0;
}

