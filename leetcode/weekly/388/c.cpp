class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= arr[i].size(); j++) {
                for (int k = 0; k + j <= arr[i].size(); k++) {
                    bool ok = true;
                    auto s = arr[i].substr(k, j);
                    for (int ii = 0; ii < n; ii++) {
                        if (ii == i) continue;
                        if (arr[ii].find(s) != string::npos) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        if (ans[i].empty()) ans[i] = s;
                        else ans[i] = min(ans[i], s);
                    }
                }
                if (!ans[i].empty()) break;
            }
        }
        return ans;
    }
};
