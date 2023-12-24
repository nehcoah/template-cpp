class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int inf = 0x3f3f3f3f;
        vector<vector<int>> w(26, vector<int>(26, inf));
        for (int i = 0; i < original.size(); i++) {
            w[original[i] - 'a'][changed[i] - 'a'] = min(w[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int p = 0; p < 26; p++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (w[source[i] - 'a'][target[i] - 'a'] == inf) return -1;
                ans += w[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};
