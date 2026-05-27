#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
#include<set>
#include<algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_map<char, pair<bool, bool> > words;
        for (int i = 0; i < word.size();i++) {
            if (isupper(word[i])) {
                if (words[tolower(word[i])].first && !words[tolower(word[i])].second)
                    ans++;
                words[tolower(word[i])].second = true;
            }
            else {
                if (!words[word[i]].first && words[word[i]].second)
                    ans++;
                words[word[i]].first = true;
            }
        }
        return ans;
    }
};