#include <string>
#include<unordered_map>
#include <algorithm>
using namespace std;

struct vowel {
    int count = 0, firstOccurence = 0;
    char ch;
};

struct comp {
    bool operator()(const vowel& a, const vowel& b) const {
        if (a.count == b.count)
            return a.firstOccurence < b.firstOccurence;
        return a.count > b.count;
    }
};

class Solution {
public:
    unordered_map<char, vowel> mp;
    string sortVowels(string s) {
        for (int i = 0; i < s.size();i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if (mp.find(s[i]) == mp.end()) {
                    mp[s[i]] = vowel({ 1, i, s[i]});
                }
                else
                    mp[s[i]].count++;
            }
        }
        vector<vowel> v;
        for (auto i : mp) {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end(), comp());
        
        string ans = "";
        int index = 0;
        for (auto i : s) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                ans += v[index].ch;
                v[index].count--;
                if (v[index].count <= 0)
                    index++;
            }
            else
                ans += i;
        }
        return ans;
    }

};

//int main() {
//    string s = "aeiaaioooa";
//    Solution obj = Solution();
//    return obj.sortVowels(s).size();
//}