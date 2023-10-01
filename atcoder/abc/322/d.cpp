#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void rotate(array<string, 4> &cur) {
    array<string, 4> ans;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans[3 - j] += cur[i][j];
        }
    }
    cur = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 4> a, b, c;
    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> b[i];
    for (int i = 0; i < 4; i++) cin >> c[i];

    for (int da = 0; da < 4; da++) {
        for (int db = 0; db < 4; db++) {
            for (int dc = 0; dc < 4; dc++) {
                for (int ax = -3; ax <= 3; ax++) {
                    for (int ay = -3; ay <= 3; ay++) {
                        for (int bx = -3; bx <= 3; bx++) {
                            for (int by = -3; by <= 3; by++) {
                                for (int cx = -3; cx <= 3; cx++) {
                                    for (int cy = -3; cy <= 3; cy++) {
                                        array<string, 4> ans;
                                        bool ok = true;
                                        auto cover = [&](auto &s, int dx, int dy) {
                                            for (int i = 0; i < 4; i++) {
                                                for (int j = 0; j < 4; j++) {
                                                    int x = i + dx, y = j + dy;
                                                    if (s[i][j] == '#') {
                                                        if (x >= 0 && x < 4 && y >= 0 && y < 4 && ans[x][y] != '#') ans[x][y] = '#';
                                                        else ok = false;
                                                    }
                                                }
                                            }
                                        };
                                        ans.fill("....");
                                        cover(a, ax, ay);
                                        cover(b, bx, by);
                                        cover(c, cx, cy);
                                        for (int i = 0; i < 4; i++) {
                                            if (ans[i] != "####") ok = false;
                                        }
                                        if (ok) {
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                rotate(c);
            }
            rotate(b);
        }
        rotate(a);
    }

    cout << "No" << endl;

    return 0;
}
