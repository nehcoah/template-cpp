class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            string s = to_string(x);
            char mx = *max_element(s.begin(), s.end());
            for (char &c : s) c = mx;
            ans += stoi(s);
        }
        return ans;
    }
};
