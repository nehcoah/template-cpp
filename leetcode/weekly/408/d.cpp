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

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        UnionFind uf(n + 2);

        auto check = [&](int i, int j) {
            long long x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
            long long x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
            return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r1 + r2) * (r1 + r2);
        };
        for (int i = 0; i < n; i++) {
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (r >= x || r >= Y - y) uf.merge(i, n);
            if (r >= X - x || r >= y) uf.merge(i, n + 1);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (check(i, j)) uf.merge(i, j);
            }
        }
        return uf.find(n) != uf.find(n + 1);
    }
};
