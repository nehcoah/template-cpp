#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N;
    cin >> n >> N;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a.push_back(N);
    int ans = 0;
    for (int i = 1, cur = 0; i < a.size(); i++) {
        ans += (a[i] - cur) * (i - 1);
        cur = a[i];
    }
    cout << ans << endl;

    return 0;
}


