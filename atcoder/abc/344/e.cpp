#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    list<int> l;
    map<int, list<int>::iterator> mp;
    for (int i = 0; i < n; i++) {
        l.push_back(a[i]);
        mp[a[i]] = prev(l.end());
    }

    int q;
    cin >> q;
    while (q--) {
        int o; cin >> o;
        if (o == 1) {
            int x, y;
            cin >> x >> y;
            auto it = mp[x];
            mp[y] = l.insert(next(it), y);
        } else {
            int x; cin >> x;
            l.erase(mp[x]);
            mp.erase(x);
        }
    }

    for (int x : l) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
