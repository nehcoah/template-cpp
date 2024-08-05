#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector f(n, vector<int>(4, -1));
    auto dfs = [&](auto self, int i, int pre) {
        if (i == n) return 0;
        if (f[i][pre] != -1) return f[i][pre];
        int ans = 0;
        if (s[i] == 'R') {
            if (pre != 1) ans = max(ans, self(self, i + 1, 1) + 1);
            if (pre != 0) ans = max(ans, self(self, i + 1, 0));
        } else if (s[i] == 'P') {
            if (pre != 2) ans = max(ans, self(self, i + 1, 2) + 1);
            if (pre != 1) ans = max(ans, self(self, i + 1, 1));
        } else {
            if (pre != 0) ans = max(ans, self(self, i + 1, 0) + 1);
            if (pre != 2) ans = max(ans, self(self, i + 1, 2));
        }
        return f[i][pre] = ans;
    };

    cout << dfs(dfs, 0, 3) << endl;

    return 0;
}
