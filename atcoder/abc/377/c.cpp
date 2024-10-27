#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dirs[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};

    int n, m;
    cin >> n >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        st.emplace(a, b);
        for (auto [dx, dy] : dirs) {
            int nx = a + dx, ny = b + dy;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                st.emplace(nx, ny);
            }
        }
    }
    cout << 1ll * n * n - st.size() << "\n";

    return 0;
}

