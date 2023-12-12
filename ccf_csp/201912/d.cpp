// 70

#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> link(n, {0});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int t, k;
    cin >> t >> k;

    vector<vector<int>> op(k);
    string s, ss;
    getline(cin, s);
    for (int i = 0; i < k; i++) {
        getline(cin, s);
        stringstream io(s);
        vector<int> tmp;
        while (getline(io, ss, ' ')) {
            tmp.push_back(stoi(ss));
        }
        tmp[0]--;
        op[i] = std::move(tmp);
    }

    priority_queue<pair<int, pair<vector<int>, int>>> pq; // [time, from, to]

    auto append = [&](int d, int from) {
        for (int x : adj[from]) {
            if (link[from] != link[x]) pq.push({-d - t, {link[from], x}});
        }
    };

    for (int i = 0; i < k; ) {
        vector<int> update(n, false);

        int cur = op[i][1];
//        cout << cur << endl;
        while (!pq.empty() && -get<0>(pq.top()) <= cur) {
            auto c = pq.top(); pq.pop();
            auto d = -c.first;
            auto l = c.second.first;
            auto to = c.second.second;
            if (link[to].size() < l.size()) {
                link[to] = l;
                append(d, to);
                update[to] = true;
            } else if (l.size() == link[to].size() && l.back() < link[to].back()) {
                link[to] = l;
                append(d, to);
                update[to] = true;
            }
        }

        vector<pair<int, int>> add; // id, add
        vector<int> query; // id
        while (i < k && op[i][1] == cur) {
            if (op[i].size() == 2) query.push_back(op[i][0]);
            else add.emplace_back(op[i][0], op[i][2]);
            i++;
        }

        for (auto a : add) {
            link[a.first].push_back(a.second);
            update[a.first] = true;
        }
        for (int x : query) {
            cout << link[x].size() << " ";
            for (int y : link[x]) cout << y << " ";
            cout << "\n";
        }

        for (int j = 0; j < n; j++) {
            if (update[j]) {
                for (int x : adj[j]) {
                    if (link[j] != link[x]) pq.push({-cur - t, {link[j], x}});
                }
            }
        }
    }

    return 0;
}

