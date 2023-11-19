#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<set<int>> c(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c[i].insert(x);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (c[a].size() > c[b].size()) c[b].swap(c[a]);
        for (int x : c[a]) c[b].insert(x);
        c[a].clear();
        cout << c[b].size() << "\n";
    }

    return 0;
}


