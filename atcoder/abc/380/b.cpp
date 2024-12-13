#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n - 1; ) {
        int j = i + 1;
        while (s[j] == '-') j += 1;
        cout << j - i - 1 << " ";
        i = j;
    }
    cout << "\n";

    return 0;
}
