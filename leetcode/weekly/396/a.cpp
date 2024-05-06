class Solution {
public:
    bool isValid(string word) {
        auto check = [&](char c) {
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || 
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        int ans = 0;
        if (word.size() < 3) ans = -1;
        for (char c : word) {
            if (islower(c) || isupper(c)) {
                if (check(c)) ans |= 1;
                else ans |= 2;
            } else if (!isdigit(c)) {
                ans = -1;
            }
        }
        return ans == 3;
    }
};
