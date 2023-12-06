// 64

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 998244353;
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> f(n + 1, vector<int>(4));
    unordered_map<string, int> mp;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        unordered_map<string, int> tmp;
        f[i][0] = f[i - 1][2];
        f[i][1] = f[i - 1][0];
        f[i][2] = (f[i - 1][1] + f[i - 1][3]) % mod;
        f[i][3] = (f[i - 1][3] + f[i - 1][2]) % mod;
        tmp["16"] = f[i - 1][2];
        tmp["26"] = mp["16"];
        tmp["46"] = (mp["66"] + mp["26"]) % mod;
        tmp["66"] = mp["46"];
        tmp["64"] = (f[i - 1][3] + mp["42"]) % mod;
        tmp["41"] = mp["64"];
        tmp["62"] = mp["41"];
        tmp["44"] = mp["62"];
        tmp["61"] = mp["44"];
        tmp["42"] = mp["61"];
        mp.swap(tmp);
    }

    if (s.size() == 1) {
        if (s[0] == '1') cout << f[n][0] << "\n";
        else if (s[0] == '2') cout << f[n][1] << "\n";
        else if (s[0] == '4') cout << f[n][2] << "\n";
        else cout << f[n][3] << "\n";
    } else if (s.size() == 2) {
        cout << mp[s] << "\n";
    } else {

    }

    return 0;
}

