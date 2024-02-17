#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    unordered_map<char, pair<int, int>> dirs {{'L', {0, -1}}, {'R', {0, 1}},
                                              {'U', {-1, 0}}, {'D', {1, 0}}};
    auto check = [&](int x, int y) {
        if (s[x][y] == '#') return false;
        for (char c : t) {
            auto [dx, dy] = dirs[c];
            x += dx, y += dy;
            if (s[x][y] == '#') return false;
        }
        return true;
    };
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans += check(i, j);
        }
    }
    cout << ans << endl;

    return 0;
}

