#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    vector<vector<int>> pos(1e4 + 1);
    for (int i = 0, pre = -1; i < n; i++) {
        pos[a[i]].push_back(i);
        if (a[i] == 0) {
            if (i - pre > 1) mp[pre + 1] = i - 1;
            pre = i;
        }
        if (i == n - 1) {
            if (i > pre) mp[pre + 1] = n - 1;
        }
    }
    int ans = mp.size();
    for (int i = 1; i < pos.size() && !mp.empty(); i++) {
        for (int p : pos[i]) {
            auto it = mp.upper_bound(p);
            if (it == mp.begin()) break;
            it = prev(it);
            int l = it->first, r = it->second;
            mp.erase(it);
            if (l < p) mp[l] = p - 1;
            if (p < r) mp[p + 1] = r;
        }
        ans = max(ans, int(mp.size()));
    }
    cout << ans << endl;

    return 0;
}


