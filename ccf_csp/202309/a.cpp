#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> dx(n), dy(n);
    for (int i = 0; i < n; i++) {
        cin >> dx[i] >> dy[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < n; j++) {
            x += dx[j], y += dy[j];
        }
        cout << x << " " << y << "\n";
    }

    return 0;
}


