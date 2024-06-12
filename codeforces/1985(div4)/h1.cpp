#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> parent, size;
    int cnt;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        cnt = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        --cnt;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    UnionFind uf(m * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i < n - 1 && s[i + 1][j] == '#') uf.merge(i * m + j, (i + 1) * m + j);
                if (j < m - 1 && s[i][j + 1] == '#') uf.merge(i * m + j, i * m + j + 1);
            }
        }
    }

    int ans = 0;
    vector<int> vis(n * m, -1);
    for (int r = 0; r < n; r++) {
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (s[r][i] == '.') cur += 1;
            for (int x = max(0, r - 1); x <= min(n - 1, r + 1); x++) {
                if (s[x][i] == '#') {
                    int t = uf.find(x * m + i);
                    if (vis[t] != r) {
                        vis[t] = r;
                        cur += uf.size[t];
                    }
                }
            }
        }
        ans = max(ans, cur);
    }
    vis.assign(n * m, -1);
    for (int c = 0; c < m; c++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][c] == '.') cur += 1;
            for (int x = max(0, c - 1); x <= min(m - 1, c + 1); x++) {
                if (s[i][x] == '#') {
                    int t = uf.find(i * m + x);
                    if (vis[t] != c) {
                        vis[t] = c;
                        cur += uf.size[t];
                    }
                }
            }
        }
        ans = max(ans, cur);
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

