#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> cnt(n);
    deque<pair<ll, ll>> dq;
    ll sum = 0, ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cnt[p[i]]++;
        while (cur < n && cnt[cur]) cur++;
        sum += cur;
        dq.emplace_back(cur, 1);
    }
    ans = sum;
    for (int i = 0; i < n; i++) {
        sum -= dq.front().first;
        dq.front().second--;
        if (dq.front().second == 0) dq.pop_front();
        pair<ll, ll> t = {p[i], 0};
        while (!dq.empty() && dq.back().first >= p[i]) {
            sum -= (dq.back().first - p[i]) * dq.back().second;
            t.second += dq.back().second;
            dq.pop_back();
        }
        sum += n;
        dq.push_back(t);
        dq.emplace_back(n, 1);
        ans = max(ans, sum);
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

