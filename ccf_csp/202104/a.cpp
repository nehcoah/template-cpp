#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, L;
    cin >> n >> m >> L;
    vector<int> h(L);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            h[x]++;
        }
    }
    for (int i = 0; i < L; i++) {
        cout << h[i] << " \n"[i == L - 1];
    }

    return 0;
}


