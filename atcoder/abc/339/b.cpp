#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;

    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int d = 0, x = 0, y = 0;
    vector<string> ans(h, string(w, '.'));

    for (int i = 0; i < n; i++) {
        if (ans[x][y] == '.') {
            ans[x][y] = '#';
            d = (d + 1) % 4;
        } else {
            ans[x][y] = '.';
            d = (d + 3) % 4;
        }
        x = (x + dirs[d][0]) % h;
        if (x < 0) x += h;
        y = (y + dirs[d][1]) % w;
        if (y < 0) y += w;
    }

    for (int i = 0; i < h; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
