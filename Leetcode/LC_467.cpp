#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        unordered_map<char, int> longestString;
        longestString[s[0]] = 1;
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if ((s[i] - 'a') - (s[i - 1] - 'a') == 1 || (s[i] == 'a' && s[i - 1] == 'z'))
                count++;
            else
                count = 1;
            if (longestString[s[i]] < count)
                longestString[s[i]] = count;
        }
        int sum = 0;
        for (auto i : longestString)
            sum += i.second;
        return sum;
    }
};