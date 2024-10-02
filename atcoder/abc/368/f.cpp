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

    int mx = *max_element(a.begin(), a.end());
    vector<vector<int>> d(mx + 1);
    for (int i = 1; i <= mx; i++) {
        for (int j = 2 * i; j <= mx; j += i) {
            d[j].push_back(i);
        }
    }

    vector<int> sg(mx + 1);
    for (int x = 1; x <= mx; x++) {
        int k = d[x].size();
        vector<int> cnt(k + 1);
        for (int y : d[x]) {
            if (sg[y] <= k) cnt[sg[y]] = 1;
        }
        while (cnt[sg[x]]) {
            sg[x] += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= sg[a[i]];
    }
    if (ans > 0) cout << "Anna\n";
    else cout << "Bruno\n";

    return 0;
}

