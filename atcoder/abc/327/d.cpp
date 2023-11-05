#include "bits/stdc++.h"

using namespace std;
using ll = long long;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size(), color[n];
    memset(color, 0, sizeof(color));
    function<bool(int, int)> dfs = [&](int i, int c){
        color[i] = c;
        for (auto nxt : graph[i]){
            if (color[nxt] == c || color[nxt] == 0 && !dfs(nxt, 3 - c)){
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            if (!dfs(i, 1)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < m; i++) cin >> b[i], b[i]--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    cout << (isBipartite(adj) ? "Yes" : "No") << endl;

    return 0;
}

