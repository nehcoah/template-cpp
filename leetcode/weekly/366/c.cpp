class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> idx;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) idx.push_back(i);
        }
        if (idx.size() % 2 == 1) return -1;

        vector<int> f(idx.size() + 1, 1e9);
        f[0] = 0;
        for (int i = 0; i < idx.size(); i++) {
            if (i & 1) f[i + 1] = f[i] + x;
            else f[i + 1] = f[i];
            if (i > 0) f[i + 1] = min(f[i + 1], f[i - 1] + idx[i] - idx[i - 1]);
        }
        return f.back();
    }
};
