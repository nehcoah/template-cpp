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

    auto check = [&](int x, int y) {
        set<pair<int, int>> st;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (abs(x - i) + abs(y - j) <= d && s[i][j] == '.') {
                    st.emplace(i, j);
                }
            }
        }
        return st;
    };

    vector<pair<int, int>> p;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                p.emplace_back(i, j);
            }
        }
    }

    int ans = 0;
    for (auto [x1, y1] : p) {
        auto s1 = check(x1, y1);
        for (auto [x2, y2] : p) {
            auto s2 = check(x2, y2);
            for (auto &q : s1) {
                s2.insert(q);
            }
            ans = max(ans, int(s2.size()));
        }
    }
    cout << ans << endl;

    return 0;
}

