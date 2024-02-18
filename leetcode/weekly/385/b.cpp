class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<unordered_set<int>> st(10);
        for (int x : arr1) {
            auto s = to_string(x);
            int n = s.size();
            while (x) {
                st[n].insert(x);
                x /= 10;
                n--;
            }
        }
        int ans = 0;
        for (int x : arr2) {
            auto s = to_string(x);
            int n = s.size();
            for (int i = n; i >= 0; i--) {
                if (st[i].count(x)) {
                    ans = max(ans, i);
                    break;
                }
                x /= 10;
            }
        }
        return ans;
    }
};
