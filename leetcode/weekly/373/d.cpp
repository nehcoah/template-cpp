class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        // v -> 1, c -> -1
        // [l, r] -> sum = 0 and ((r - l) / 2) * ((r - l) / 2) % k == 0 
        //                    -> (r - l) * (r - l) % 4k == 0 
        //                    -> (r - l) % 2k' == 0
        //                    -> r % 2k' == l % 2k'
        int K = 1;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) {
                    k /= i;
                    cnt++;
                }
                K *= pow(i, (cnt + 1) / 2);
            }
        }
        if (k > 1) K *= k;
        K *= 2;
        
        auto check = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        map<pair<int, int>, int> mp;
        mp[{0, K - 1}] = 1;
        int sum = 0;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += check(s[i]) ? 1 : -1;
            ans += mp[{sum, i % K}];
            mp[{sum, i % K}]++;
        }
        return ans;
    }
};
