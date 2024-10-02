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
    priority_queue<int> pq;
    for (int x : a) {
        pq.push(x);
    }

    int ans = 0;
    while (true) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        if (y <= 0) break;
        pq.push(x - 1); pq.push(y - 1);
        ans += 1;
    }
    cout << ans << endl;

    return 0;
}

