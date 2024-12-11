#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

//template <typename K, typename V, typename Comp = std::less<K>>
//using ordered_map = __gnu_pbds::tree<
//        K, V, Comp,
//        __gnu_pbds::rb_tree_tag,
//        __gnu_pbds::tree_order_statistics_node_update
//>;
//
//template <typename K, typename Comp = std::less<K>>
//using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    int ans = 0;
    vector vis(h, vector<int>(w));
    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'H') {
                q.emplace(i, j);
                vis[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    while (!q.empty() && cnt <= d) {
        for (int i = q.size(); i; i--) {
            auto [x, y] = q.front(); q.pop();
            ans += 1;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && s[nx][ny] == '.') {
                    q.emplace(nx, ny);
                    vis[nx][ny] = 1;
                }
            }
        }
        cnt += 1;
    }
    cout << ans << endl;

    return 0;
}

