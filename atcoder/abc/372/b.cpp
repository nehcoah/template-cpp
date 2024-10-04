#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<int> cnt;
    while (m) {
        cnt.push_back(m % 3);
        m /= 3;
    }
    vector<int> ans;
    for (int i = 0; i < cnt.size(); i++) {
        for (int j = 0; j < cnt[i]; j++) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}

