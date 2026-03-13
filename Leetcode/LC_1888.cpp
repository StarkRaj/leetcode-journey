#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        int patternA = 0, patternB = 0; //patternA = 0101010.....  patternB = 101010101.....
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            char expectedA = (i % 2 == 0) ? '0' : '1';      // patternA requires 0 at even positions
            char expectedB = (i % 2 == 0) ? '1' : '0';      // vice versa
            if (s[i] != expectedA)
                patternA++;
            if (s[i] != expectedB)
                patternB++;
            if (i >= n) {
                char expectedA = ((i-n) % 2 == 0) ? '0' : '1';
                char expectedB = ((i-n) % 2 == 0) ? '1' : '0';
                if (s[i-n] != expectedA)
                    patternA--;
                if (s[i-n] != expectedB)
                    patternB--;
            }
            if(i >= n-1)
                ans = min(ans, min(patternA, patternB));
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int ans = obj.minFlips("111000");
    return 0;
}