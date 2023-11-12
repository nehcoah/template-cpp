#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template <typename T>
struct WeightUnionFind {
    vector<int> parent, size;
    vector<T> w;
    int cnt;

    WeightUnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
        cnt = n;
        w.resize(n, T());
    }

    int find(int x) {
        if (parent[x] == x) return x;
        int r = find(parent[x]);
        w[x] += w[parent[x]];
        parent[x] = r;
        return r;
    }

    bool merge(int x, int y, T d) {
        d += w[x];
        d -= w[y];
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) {
            swap(x, y);
            d = -d;
        }
        parent[y] = x;
        size[x] += size[y];
        w[y] = d;
        cnt--;
        return true;
    }

    T weight(int x) {
        find(x);
        return w[x];
    }

    T diff(int x, int y) {
        find(x);
        find(y);
        return w[y] - w[x];
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    WeightUnionFind<ll> uf(n);
    for (int i = 0; i < q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        if (!uf.is_connected(a, b)) {
            cout << i + 1 << " ";
            uf.merge(a, b, d);
        } else {
            if (uf.diff(a, b) == d) cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}

