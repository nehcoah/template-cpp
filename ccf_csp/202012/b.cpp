#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, tot = 0;
    cin >> m;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < m; i++) {
        int y, r;
        cin >> y >> r;
        mp[y].first += r == 0;
        mp[y].second += r == 1;
        tot += r;
    }

    int ans = 0, pred = 0, sum0 = 0, sum1 = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int cur = sum0 + tot - sum1;
        if (cur >= pred) {
            pred = cur;
            ans = max(ans, it->first);
        }
        sum0 += it->second.first;
        sum1 += it->second.second;
    }
    cout << ans << endl;

    return 0;
}


