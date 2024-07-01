#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        p[a[i]].push_back(w[i]);
    }
    int ans = 0;
    for (auto &q : p) {
        if (!q.empty()) ans += accumulate(q.begin(), q.end(), 0) - *max_element(q.begin(), q.end());
    }
    cout << ans << endl;


    return 0;
}
