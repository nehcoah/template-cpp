//
// Created by Nehcoah on 2023/9/14.
// MST (Minimum Spanning Tree)
//

#include <vector>
#include <functional>
#include <numeric>

using namespace std;

// edges[i] = [start, end, weight]
int kruskal(int n, vector<vector<int>>& edges) {
    int cnt = n;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
        return a[2] < b[2];
    });

    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto merge = [&](int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[x] = y;
        cnt--;
        return true;
    };

    int v = 0;
    for (auto &e : edges) {
        if (merge(e[0], e[1])) v += e[2];
    }
    return v;
}