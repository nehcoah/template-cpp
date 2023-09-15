//
// Created by Nehcoah on 2023/9/14.
// MST (Minimum Spanning Tree)
//

#include <vector>
#include <functional>
#include <numeric>

using namespace std;

// kruskal algorithm
// edges[i] = [start, end, weight]
// n = edges.size()
// time: O(nlog(n)), depends on edges
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

// prim algorithm
// g = Adjacency Matrix
// n = adj.size()
// time: O(n^2), depend on points
int prim(vector<vector<int>> &g, int start) {
    int ans = 0;
    int n = g.size();
    vector<int> lowcost(n, INT_MAX);
    vector<int> vis(n);

    lowcost[start] = 0;
    for (int i = 0; i < n; i++) {
        int minIdx = -1;
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0 && lowcost[j] <= minVal) {
                minIdx = j;
                minVal = lowcost[j];
            }
        }
        vis[minIdx] = 1;
        ans += minVal;

        for (int j = 0; j < n; j++) {
            if (vis[j] == 0) lowcost[j] = min(lowcost[j], g[j][minIdx]);
        }
    }
    return ans;
}
