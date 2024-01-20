#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    int ans = numeric_limits<int>::max();
    if (h >= k) {
        for (int i = 0; i < w; i++) {
            int cnt_o = 0, cnt_x = 0;
            for (int j = 0; j < k; j++) {
                if (s[j][i] == 'o') cnt_o++;
                else if (s[j][i] == 'x') cnt_x++;
            }
            if (cnt_x == 0) ans = min(ans, k - cnt_o);
            for (int j = k; j < h; j++) {
                if (s[j][i] == 'o') cnt_o++;
                else if (s[j][i] == 'x') cnt_x++;
                if (s[j - k][i] == 'o') cnt_o--;
                else if (s[j - k][i] == 'x') cnt_x--;
                if (cnt_x == 0) ans = min(ans, k - cnt_o);
            }
        }
    }
    if (w >= k) {
        for (int i = 0; i < h; i++) {
            int cnt_o = 0, cnt_x = 0;
            for (int j = 0; j < k; j++) {
                if (s[i][j] == 'o') cnt_o++;
                else if (s[i][j] == 'x') cnt_x++;
            }
            if (cnt_x == 0) ans = min(ans, k - cnt_o);
            for (int j = k; j < w; j++) {
                if (s[i][j] == 'o') cnt_o++;
                else if (s[i][j] == 'x') cnt_x++;
                if (s[i][j - k] == 'o') cnt_o--;
                else if (s[i][j - k] == 'x') cnt_x--;
                if (cnt_x == 0) ans = min(ans, k - cnt_o);
            }
        }
    }
    cout << (ans == numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}
