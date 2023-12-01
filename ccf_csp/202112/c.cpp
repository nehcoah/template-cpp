// 40

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, s;
    cin >> w >> s;
    string str;
    cin >> str;
    int f = 0;
    vector<int> ans;
    for (char c : str) {
        if (isdigit(c)) {
            if (f != 2) {
                ans.push_back(28);
                f = 2;
            }
            ans.push_back(c - '0');
        } else if (islower(c)) {
            if (f != 1) {
                ans.push_back(27);
                f = 1;
            }
            ans.push_back(c - 'a');
        } else {
            if (f != 0) {
                if (f == 1) ans.push_back(28);
                ans.push_back(28);
                f = 0;
            }
            ans.push_back(c - 'A');
        }
    }
    if (ans.size() % 2 == 1) ans.push_back(29);
    vector<int> tmp(ans.size() / 2);
    for (int i = 0; i < ans.size(); i += 2) {
        tmp[i / 2] = ans[i] * 30 + ans[i + 1];
    }
    ans.swap(tmp);
    while ((ans.size() + 1) % w != 0) ans.push_back(900);
    cout << ans.size() + 1 << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}


