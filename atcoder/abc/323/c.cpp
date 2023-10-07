#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> score(m), a(n);
    vector<unordered_set<int>> solve(n);
    for (int i = 0; i < m; i++) cin >> score[i];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int cur = i + 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'o') {
                cur += score[j];
                solve[i].insert(j);
            }
        }
        a[i] = cur;
    }

    vector<int> ans(n), idx(m);
    int mx = *max_element(a.begin(), a.end()), cnt = 0;
    for (int x : a) if (x == mx) cnt++;
    if (cnt > 1) {
        for (int i = 0; i < n; i++) if (a[i] == mx) ans[i] = 1;
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return score[i] > score[j];
    });

    for (int i = 0; i < n; i++) {
        if (a[i] == mx) continue;
        int cur = a[i];
        for (int id : idx) {
            if (solve[i].count(id)) continue;
            cur += score[id];
            ans[i]++;
            if (cur > mx) break;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}

