#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++) {
        ll t, d;
        cin >> t >> d;
        p[i] = {t, d};
    }

    ranges::sort(p);
    ll ans = 0, cur = p[0].first, nxt = p[0].first;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 0; i < n; ) {
        while (cur < nxt) {
            while (!pq.empty() && pq.top() < cur) pq.pop();
            if (pq.empty()) break;
            pq.pop(); ans++; cur++;
        }
        cur = nxt;
        while (i < n && p[i].first == nxt) {
            pq.push(p[i].first + p[i].second);
            i++;
        }
        while (cur <= nxt) {
            while (!pq.empty() && pq.top() < cur) pq.pop();
            if (pq.empty()) break;
            pq.pop(); ans++; cur++;
        }
        if (i != n) nxt = p[i].first;
    }

    while (true) {
        while (!pq.empty() && pq.top() < cur) pq.pop();
        if (pq.empty()) break;
        pq.pop(); ans++; cur++;
    }

    cout << ans << endl;

    return 0;
}

