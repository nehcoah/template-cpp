#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, pair<int, int>> mp;
    vector<vector<array<int, 3>>> risk(7);
    for (int i = 0; i < n; i++) {
        int x, m;
        cin >> x >> m;
        for (int j = 0; j < x; j++) {
            int p; cin >> p;
            if (mp.count(p)) {
                if (mp[p].second + 1 >= i) mp[p].second = i + 6;
                else mp[p] = {i, i + 6};
            } else mp[p] = {i, i + 6};
        }

        risk[i % 7].resize(0);
        for (int j = 0; j < m; j++) {
            int d, u, r;
            cin >> d >> u >> r;
            risk[i % 7].push_back({d, u, r});
        }
        set<int> s;
        for (int j = 0; j < 7; j++) {
            for (auto &info : risk[j]) {
                int d = info[0], u = info[1], r = info[2];
//                cout << i << " " << d << " " << u << " " << r << endl;
                if (mp.count(r)) {
                    if (i - 6 <= d && mp[r].first <= d && mp[r].second >= d && mp[r].second >= i) s.insert(u);
                }
            }
        }
        cout << i << " ";
        for (int y : s) cout << y << " ";
        cout << endl;
    }

    return 0;
}


