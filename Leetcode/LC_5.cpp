#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strSize = s.size();
        if(strSize == 1)
            return s;
        vector<vector<bool> >dp = vector<vector<bool>>(strSize, vector<bool>(strSize, false));
        string ans = s.substr(0,1);
        for(int i=0; i<strSize; i++){
            dp[i][i] = true;
            for(int j=0; j<i; j++){
                if(s[i] == s[j] && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(i-j+1 > ans.size()){
                        ans = s.substr(j,i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babad");
}