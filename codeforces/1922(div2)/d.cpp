#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    set<int> alive, die;
    for (int i = 0; i < n; i++) {
        alive.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (i > 0) x += a[i - 1];
        if (i < n - 1) x += a[i + 1];
        if (x > d[i]) die.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cout << die.size() << " \n"[i == n - 1];

        auto check = [&](auto it) {
            int x = 0, id = *it;
            if (it != alive.begin()) {
                x += a[*prev(it)];
            }
            if (it != prev(alive.end())) {
                x += a[*next(it)];
            }
            return x > d[id];
        };

        set<int> nxt;
        for (int x : die) {
            alive.erase(x);
        }
        for (int x : die) {
            auto it = alive.lower_bound(x);
            if (it != alive.end() && check(it)) nxt.insert(*it);
            if (it != alive.begin() && check(prev(it))) nxt.insert(*prev(it));
        }
        die.swap(nxt);
    }
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
