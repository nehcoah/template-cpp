#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    map<int, int> mp;
    vector<int> cnt(n, 1);
    mp[-1] = -1;
    for (int i = 0; i < n; i++) {
        mp[i] = i;
    }
    mp[n] = -1;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, c; cin >> x >> c;
            x -= 1, c -= 1;
            auto itr = prev(mp.upper_bound(x));
            cnt[itr->second] -= next(itr)->first - itr->first;
            cnt[c] += next(itr)->first - itr->first;
            itr->second = c;
            if (next(itr)->second == itr->second) mp.erase(next(itr));
            if (itr->second == prev(itr)->second) mp.erase(itr);
        } else {
            int c; cin >> c;
            c -= 1;
            cout << cnt[c] << "\n";
        }
    }

    return 0;
}
