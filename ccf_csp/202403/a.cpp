#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1), cnt_all(m + 1);
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        vector<int> cur(m + 1);
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            cur[x] = 1;
            cnt_all[x] += 1;
        }
        for (int j = 0; j <= m; j++) {
            cnt[j] += cur[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " " << cnt_all[i] << endl;
    }

    return 0;
}
