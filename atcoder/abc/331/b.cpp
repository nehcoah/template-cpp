#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int ans = 1e9;
    function<void(int, int)> dfs = [&](int x, int cur) {
        if (x >= n) {
            ans = min(ans, cur);
            return;
        }
        dfs(x + 6, cur + s);
        dfs(x + 8, cur + m);
        dfs(x + 12, cur + l);
    };
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}


