class Solution {
public:
    int reverse(int x) {
        long long revN = 0;
        while (x != 0) {
            int ldigit = x % 10;
            if (revN > INT_MAX / 10 || revN < INT_MIN / 10)
                return 0;
            revN = (revN * 10) + ldigit;
            x = x / 10;
        }
        return (revN < INT_MIN || revN > INT_MAX) ? 0 : (int)revN;
    }
};