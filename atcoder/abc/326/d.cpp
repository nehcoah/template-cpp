#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string r, c;
    cin >> r >> c;

    vector<string> ans(n, string(n, '.'));
    vector<unordered_set<char>> row(n), col(n);
    int cnt = 0;
    bool ok = false;
    auto dfs = [&](auto self, int x, int y) {
        if (ok) return;
        if (x == n) {
            if (cnt == 3 * n) {
                cout << "Yes" << endl;
                for (int i = 0; i < n; i++) cout << ans[i] << endl;
                ok = true;
            }
            return;
        }
        if (y == n) {
            self(self, x + 1, 0);
            return;
        }
        self(self, x, y + 1);
        for (char cur = 'A'; cur <= 'C'; cur++) {
            if (col[y].empty() && c[y] != cur) continue;
            if (row[x].empty() && r[x] != cur) continue;
            if (row[x].count(cur)) continue;
            if (col[y].count(cur)) continue;
            ans[x][y] = cur;
            row[x].insert(cur);
            col[y].insert(cur);
            cnt++;
            self(self, x, y + 1);
            ans[x][y] = '.';
            row[x].erase(cur);
            col[y].erase(cur);
            cnt--;
        }
    };

    dfs(dfs, 0, 0);
    if (!ok) cout << "No" << endl;

    return 0;
}

