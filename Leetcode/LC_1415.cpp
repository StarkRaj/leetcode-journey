#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string ans = "";
    vector<char> v = { 'a', 'b', 'c' };

    void backtracking(int& n, int& k, string s) {
        if (ans != "")
            return;
        if (s.size() == n && k == 0) {
            ans = s;
            return;
        }
        if (s.size() >= n || k < 0)
            return;
        for (char i : v) {
            if (s.length() > 0 && i == s.back())
                continue;
            s += i;
            if (s.length() == n)
                k--;
            backtracking(n, k, s);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        ans = "";
        string initialString = "";
        backtracking(n, k, initialString);
        return ans;
    }
};
