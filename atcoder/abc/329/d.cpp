#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> vote(n + 1);
    int mx = 0, idx = -1;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        vote[x]++;
        if (vote[x] > mx) {
            mx = vote[x];
            idx = x;
        } else if (vote[x] == mx) {
            if (x < idx) idx = x;
        }
        cout << idx << "\n";
    }

    return 0;
}


