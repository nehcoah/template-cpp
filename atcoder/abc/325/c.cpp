#include "bits/stdc++.h"

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

    bool merge(int x, int y){
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

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    map<pair<int, int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') mp[{i, j}] = cnt++;
        }
    }

    UnionFind uf(cnt);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] != '#') continue;
            auto cur = mp[{i, j}];
            if (j < w - 1 && s[i][j + 1] == '#') uf.merge(cur, mp[{i, j + 1}]);
            if (i < h - 1 && s[i + 1][j] == '#') uf.merge(cur, mp[{i + 1, j}]);
            if (i < h - 1 && j < w - 1 && s[i + 1][j + 1] == '#') uf.merge(cur, mp[{i + 1, j + 1}]);
            if (i < h - 1 && j > 0 && s[i + 1][j - 1] == '#') uf.merge(cur, mp[{i + 1, j - 1}]);
        }
    }

    cout << uf.cnt << endl;

    return 0;
}

