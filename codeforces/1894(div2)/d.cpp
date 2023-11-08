#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    set<int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (st.count(a[i]) == 0) pq.emplace(a[i], i), st.insert(a[i]);
    }
    ranges::sort(b, greater<>());
    vector<vector<int>> nums(n + 1);
    int i = 0, idx = 0;
    while (!pq.empty()) {
        for (; i < m && b[i] >= pq.top().first; i++) nums[idx].push_back(b[i]);
        idx = pq.top().second + 1;
        pq.pop();
    }
    for (int x : nums[0]) cout << x << " ";
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
        for (int x : nums[j + 1]) cout << x << " ";
    }
    for (; i < m; i++) cout << b[i] << " ";
    cout << endl;
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

