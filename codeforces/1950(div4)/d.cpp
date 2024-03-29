#include "bits/stdc++.h"

using namespace std;
using ll = long long;

unordered_set<int> st;
vector<int> nums;
void init() {
    auto dfs = [&](auto self, int i, int cur) {
        if (i == 6) return;
        st.insert(cur);
        self(self, i + 1, cur * 10);
        self(self, i + 1, cur * 10 + 1);
    };
    dfs(dfs, 0, 0);
    for (int x : st) {
        if (x > 1) nums.push_back(x);
    }
}

void solve() {
    int n;
    cin >> n;
    if (st.count(n)) {
        cout << "YES\n";
        return;
    }
    bool ok = false;
    auto dfs = [&](auto self, ll cur, int i) -> void {
        if (ok) return;
        if (cur == n) ok = true;
        if (cur > n) return;
        for (int j = i; j < nums.size(); j++) {
            self(self, cur * nums[j], j);
        }
    };
    dfs(dfs, 1, 0);
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();

    while (t--) {
        solve();
    }

    return 0;
}
