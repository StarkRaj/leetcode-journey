#include <vector>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (auto i : nums) {
            if (i >= n)
                return false;
            count[i]++;
        }
        if (count[n - 1] != 2)
            return false;
        for (int i = 1; i < n - 1;i++) {
            if (count[i] != 1)
                return false;
        }
        return true;
    }
};
//
//int main() {
//    vector<int> v = { 1,3,2,3 };
//    return Solution().isGood(v);
//}