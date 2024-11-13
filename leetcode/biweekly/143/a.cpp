class Solution {
public:
    int smallestNumber(int n, int t) {
        auto check = [&](int x) {
            long long mul = 1;
            for (auto c : to_string(x)) {
                mul *= (c - '0');
            }
            return mul % t == 0;
        };
        
        for (int x = n; ; x++) {
            if (check(x)) {
                return x;
            }
        }
        return -1;
    }
};
