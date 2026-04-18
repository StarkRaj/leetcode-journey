#include <stdlib.h>

class Solution {
public:
    int getReverse(int n) {
        int reversed_number = 0, remainder = 0;
        while (n != 0) {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        return reversed_number;
    }
    int mirrorDistance(int n) {
        return abs(n - getReverse(n));
    }
};