#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> z;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        string s = to_string(a);
        sum += s.size();
        int cnt = 0;
        while (a % 10 == 0) {
            cnt += 1;
            a /= 10;
        }
        if (cnt > 0) z.push_back(cnt);
    }
    sort(z.begin(), z.end(), greater<>());
    for (int i = 0; i < z.size(); i += 2) {
        sum -= z[i];
    }
    cout << (sum <= m ? "Anna\n" : "Sasha\n");
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

