#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, S;
    cin >> n >> L >> S;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    vector<vector<int>> mp(S + 1, vector<int>(S + 1));
    for (int i = S; i >= 0; i--) {
        for (int j = 0; j <= S; j++) {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (auto it : st) {
        bool good = true;
        for (int i = S; i >= 0; i--) {
            for (int j = 0; j <= S; j++) {
                if (it.first + i > L || it.second + j > L) {
                    good = false;
                    break;
                }
                if (mp[i][j]) {
                    if (st.find({it.first + i, it.second + j}) == st.end()) {
                        good = false;
                        break;
                    }
                } else {
                    if (st.find({it.first + i, it.second + j}) != st.end()) {
                        good = false;
                        break;
                    }
                }
            }
        }
        if (good) ans++;
    }
    cout << ans << "\n";

    return 0;
}


