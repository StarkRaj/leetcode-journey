#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        int i = 0;
        vector<pair<int, int> > intervals;
        int maxLimit = min(i + maxJump, n - 1);
        intervals.push_back({ minJump, maxLimit });
        while (i < intervals.size()) {
            int low = intervals[i].first;
            while (low <= intervals[i].second) {
                if (s[low] == '0') {
                    if (low == n - 1)
                        return true;
                    int newLow = low + minJump;
                    int newHigh = min(low + maxJump, n - 1);
                    if (newLow > intervals.back().second)
                        intervals.push_back({ newLow, newHigh });
                    if (newLow <= intervals.back().second && newHigh > intervals.back().second)
                        intervals.back().second = newHigh;
                }
                low++;
            }
            i++;
        }
        return false;
    }
};

//int main() {
//    string s = "01101110";
//    return Solution().canReach(s, 2, 3);
//}