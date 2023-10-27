#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        s[i] = {l, r};
    }
    ranges::sort(s);
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ) {
        int cur = s[i].first;
        while (!pq.empty() && pq.top() < cur) pq.pop();
        while (i < n && cur == s[i].first) {
            if (s[i].second != m) pq.push(s[i].second);
            i++;
        }
        ans = max(ans, int(pq.size()));
    }
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < n; ) {
        int cur = s[i].first;
        if (cur == 1) {
            i++;
            continue;
        }
        while (!pq.empty() && pq.top() < cur) pq.pop();
        while (i < n && cur == s[i].first) {
            pq.push(s[i].second);
            i++;
        }
        ans = max(ans, int(pq.size()));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

