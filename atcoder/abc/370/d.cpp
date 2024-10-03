#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h), col(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            row[i].insert(j);
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            col[i].insert(j);
        }
    }

    int ans = h * w;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        if (row[x].contains(y)) {
            row[x].erase(y);
            col[y].erase(x);
            ans -= 1;
        } else {
            auto it = row[x].lower_bound(y);
            if (it != row[x].begin()) {
                auto pit = prev(it);
                int cx = x, cy = *pit;
                ans -= 1;
                row[x].erase(pit);
                col[cy].erase(x);
            }
            if (it != row[x].end()) {
                int cx = x, cy = *it;
                ans -= 1;
                row[x].erase(it);
                col[cy].erase(x);
            }
            it = col[y].lower_bound(x);
            if (it != col[y].begin()) {
                auto pit = prev(it);
                int cx = *pit, cy = y;
                ans -= 1;
                col[y].erase(pit);
                row[cx].erase(y);
            }
            if (it != col[y].end()) {
                int cx = *it, cy = y;
                ans -= 1;
                col[y].erase(it);
                row[cx].erase(y);
            }
        }
    }
    cout << ans << endl;

    return 0;
}

