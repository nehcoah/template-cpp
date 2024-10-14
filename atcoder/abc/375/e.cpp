#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int sum = accumulate(b.begin(), b.end(), 0);
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    sum /= 3;
    const int inf = 1e9;
    vector f(n + 1, vector(sum + 1, vector<int>(sum + 1, -1)));
    auto dfs = [&](auto self, int i, int x, int y) {
        if (x > sum || y > sum) return inf;
        if (i == n) return x == sum && y == sum ? 0 : inf;
        if (f[i][x][y] != -1) return f[i][x][y];
        int ans = inf;
        ans = min(ans, self(self, i + 1, x + b[i], y) + (a[i] == 1 ? 0 : 1));
        ans = min(ans, self(self, i + 1, x, y + b[i]) + (a[i] == 2 ? 0 : 1));
        ans = min(ans, self(self, i + 1, x, y) + (a[i] == 3 ? 0 : 1));
        return f[i][x][y] = ans;
    };
    auto ans = dfs(dfs, 0, 0, 0);
    if (ans >= inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

