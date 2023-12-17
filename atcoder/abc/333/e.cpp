#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> t(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i];
    }

    vector<int> ans(n);
    multiset<int> monster;
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 2) monster.insert(x[i]);
        else {
            if (monster.contains(x[i])) {
                ans[i] = 1;
                monster.erase(monster.find(x[i]));
            }
        }
    }
    if (!monster.empty()) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0, mx = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (t[i] == 2) {
            p[x[i]]--;
            cnt--;
        } else {
            if (ans[i] == 1) {
                p[x[i]]++;
                cnt++;
                mx = max(mx, cnt);
            }
        }
    }
    cout << mx << endl;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

