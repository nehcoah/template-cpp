#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> cur;
    auto dfs = [&](auto self, int i) {
        if (i == n) {
            if (accumulate(cur.begin(), cur.end(), 0) % k == 0) {
                for (int j = 0; j < cur.size(); j++) {
                    cout << cur[j] << " \n"[j == cur.size() - 1];
                }
            }
            return;
        }
        for (int x = 1; x <= r[i]; x++) {
            cur.push_back(x);
            self(self, i + 1);
            cur.pop_back();
        }
    };
    dfs(dfs, 0);

    return 0;
}

