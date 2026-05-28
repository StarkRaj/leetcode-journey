#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

struct mp {
    bool lower, upper;
    int lowerPosition = INT_MAX;
};

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_map<char, mp > words;
        for (int i = 0; i < word.size();i++) {
            if (words.find(tolower(word[i])) == words.end())
                words[tolower(word[i])] = { false, false };
            if(islower(word[i])) {
                words[word[i]].lower = true;
                words[word[i]].lowerPosition = i;
            }
        }
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                if (words[tolower(word[i])].lower && !words[tolower(word[i])].upper && words[tolower(word[i])].lowerPosition < i)
                    ans++;
                words[tolower(word[i])].upper = true;
            }
        }
        return ans;
    }
};

int main() {
    return Solution().numberOfSpecialChars("aaAbcBC");
}