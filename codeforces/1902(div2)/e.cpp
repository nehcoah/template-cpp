#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int trie[N][26];
int cnt[N];
int cur = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(trie, 0, sizeof(trie));
    memset(cnt, 0, sizeof(cnt));

    int n;
    cin >> n;
    vector<string> s(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int x = 0;
        sum += s[i].size();
        for (char c : s[i]) {
            int &y = trie[x][c - 'a'];
            if (y == 0) {
                y = cur++;
            }
            cnt[y]++;
            x = y;
        }
    }

    ll ans = sum * n + n * sum;
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        int x = 0;
        for (char c : s[i]) {
            int y = trie[x][c - 'a'];
            if (y == 0) break;
            x = y;
            ans -= cnt[x] * 2;
        }
    }
    cout << ans << endl;

    return 0;
}

