#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        priority_queue<int> pq;
        ll sum = 0;
        for (int j = i; j < n; j++) {
            pq.push(p[j].second);
            sum += p[j].second;
            while (!pq.empty() && sum + p[j].first - p[i].first > l) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (int) pq.size());
        }
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
