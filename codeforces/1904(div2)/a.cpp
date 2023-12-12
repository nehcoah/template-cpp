#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int dirs[4][2] = {{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};

void solve() {
    int a, b, kx, ky, qx, qy;
    cin >> a >> b >> kx >> ky >> qx >> qy;

    int ans = 0;
    auto check = [&](int x, int y) {
        vector<pair<int, int>> pos;
        for (auto d : dirs) {
            int nx = x + d[0] * a;
            int ny = y + d[1] * b;
            pos.emplace_back(nx, ny);
        }
        if (a == b) return pos;
        swap(a, b);
        for (auto d : dirs) {
            int nx = x + d[0] * a;
            int ny = y + d[1] * b;
            pos.emplace_back(nx, ny);
        }
        return pos;
    };
    auto s = check(kx, ky), t = check(qx, qy);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

