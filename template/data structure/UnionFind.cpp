//
// Created by Nehcoah on 2023/5/3.
//

#include <vector>
#include <numeric>

using namespace std;

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

    void merge(int x, int y){
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        --cnt;
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};