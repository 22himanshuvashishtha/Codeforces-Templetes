class Solution {
public:
    int mod = 1337;

    int modPow(int a, int k) {
        // Fast modular exponentiation: a^k % mod
        a %= mod;
        int result = 1;
        for (int i = 0; i < k; ++i) {
            result = (result * a) % mod;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        // Step 1: Pop last digit
        int last_digit = b.back();
        b.pop_back();

        // Step 2: Compute part1 = a^last_digit % mod
        int part1 = modPow(a, last_digit);

        // Step 3: Recursive call for remaining digits
        int part2 = modPow(superPow(a, b), 10);  // because 10^i place in base 10

        // Step 4: Combine parts
        return (part1 * part2) % mod;
    }
};
