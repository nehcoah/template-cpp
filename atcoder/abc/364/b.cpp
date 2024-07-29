#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    string t;
    cin >> t;

    unordered_map<char, pair<int, int>> mp{
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}},
    };

    x -= 1, y -= 1;
    for (char c : t) {
        auto [dx, dy] = mp[c];
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '.') {
            x = nx, y = ny;
        }
    }
    cout << x + 1 << " " << y + 1 << endl;

    return 0;
}
