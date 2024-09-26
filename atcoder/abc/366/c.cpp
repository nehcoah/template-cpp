#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x; cin >> x;
            mp[x] += 1;
        } else if (op == 2) {
            int x; cin >> x;
            mp[x] -= 1;
            if (mp[x] == 0) mp.erase(x);
        } else {
            cout << mp.size() << "\n";
        }
    }

    return 0;
}

