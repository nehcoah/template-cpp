#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector a(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> a[i][j];
    }

    unordered_set<int> st;
    for (int i = 0; i < 9; i++) {
        st.clear();
        for (int j = 0; j < 9; j++) {
            if (st.count(a[i][j])) {
                cout << "No" << endl;
                return 0;
            }
            st.insert(a[i][j]);
        }
    }

    for (int i = 0; i < 9; i++) {
        st.clear();
        for (int j = 0; j < 9; j++) {
            if (st.count(a[j][i])) {
                cout << "No" << endl;
                return 0;
            }
            st.insert(a[j][i]);
        }
    }

    auto check = [&](int x, int y) {
        st.clear();
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (st.count(a[i][j])) return false;
                st.insert(a[i][j]);
            }
        }
        return true;
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!check(i * 3, j * 3)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

