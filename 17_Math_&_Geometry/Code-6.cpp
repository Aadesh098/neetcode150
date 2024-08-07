// Pow(x, n)
// https://leetcode.com/problems/powx-n/

double myPow(double x, int n) {
        long exponent = abs(n);
        double curr = x;
        double result = 1.0;
        for (long i = exponent; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= curr;
            }
            curr *= curr;
        }
        if (n < 0) {
            return 1.0 / result;
        }
        return result;
    }