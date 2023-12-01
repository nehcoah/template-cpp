#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1005;
    int n, m;
    cin >> n >> m;
    vector<int> ntos(n + 1);
    vector<bitset<N>> node(m + 1);
    vector<int> cnt(n + 1);
    map<int, bitset<N>> atos, aton;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        node[x].set(i);
        ntos[i] = x;
    }
    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        bitset<N> cur;
        cur.set();
        if (na) cur &= node[na];
        if (pa) {
            bitset<N> s;
            for (int j = 1; j < m + 1; j++) {
                if (atos[pa][j]) s |= node[j];
            }
            cur &= s;
        }
        auto tmp = cur;
        if (paa) cur = cur ^ (cur & aton[paa]);

        priority_queue<pair<int, int>> pq1, pq2;
        for (int j = 1; j <= n; j++) {
            if (tmp[j]) {
                if (cur[j]) pq1.emplace(-cnt[j], -j);
                else pq2.emplace(-cnt[j], -j);
            }
        }
        while (f) {
            if (!pq1.empty()) {
                auto t = pq1.top();
                pq1.pop();
                cout << -t.second << " \n"[f == 1];
                cnt[-t.second]++;
                aton[a].set(-t.second);
                atos[a].set(ntos[-t.second]);
                if (a == paa) {
                    if (paar == 0) pq2.emplace(t.first - 1, t.second);
                } else pq1.emplace(t.first - 1, t.second);
            } else if (paar == 0) {
                if (pq2.empty()) break;
                auto t = pq2.top();
                pq2.pop();
                cout << -t.second << " \n"[f == 1];
                cnt[-t.second]++;
                aton[a].set(-t.second);
                atos[a].set(ntos[-t.second]);
                pq2.emplace(t.first - 1, t.second);
            } else break;
            f--;
        }
        if (f) for (int j = 0; j < f; j++) cout << 0 << " \n"[j == f - 1];
    }

    return 0;
}


