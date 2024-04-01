#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> x(q);
    vector<vector<int>> idx(n);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
        idx[x[i] - 1].push_back(i);
    }
    vector<ll> sum(q + 1);
    set<ll> st;
    for (int i = 0; i < q; i++) {
        if (st.count(x[i])) st.erase(x[i]);
        else st.insert(x[i]);
        sum[i + 1] = sum[i] + st.size();
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        if (idx[i].size() & 1) idx[i].push_back(q);
        for (int j = 0; j < idx[i].size(); j += 2) {
            if (j + 1 < idx[i].size()) ans[i] += sum[idx[i][j + 1]] - sum[idx[i][j]];
        }
    }
    for (ll y : ans) cout << y << " ";
    cout << endl;

    return 0;
}
