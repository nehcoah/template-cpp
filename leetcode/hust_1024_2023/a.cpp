class Solution {
public:
    bool perfectPerformance(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;
        bool ok = true;
        if (mp['U'] != mp['D']) ok = false;
        if (mp['L'] != mp['R']) ok = false;
        return ok;
    }
};
