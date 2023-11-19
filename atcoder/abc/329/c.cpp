#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; ) {
        char c = s[i];
        int j = i;
        while (j < n && s[j] == c) j++;
        cnt[c - 'a'] = max(cnt[c - 'a'], j - i);
        i = j;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += cnt[i];
    }
    cout << ans << endl;

    return 0;
}


