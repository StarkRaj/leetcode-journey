#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int lowerRange = min(a, b) + 1;
            int higherRange = max(a, b) + limit;

            //2 moves
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            //One move
            diff[lowerRange] -= 1;
            diff[higherRange + 1] += 1;
            //No move
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }
        int moves = 0, ans = INT_MAX;
        for (int i = 2; i <= 2 * limit; i++) {
            moves += diff[i];
            ans = min(ans, moves);
        }
        return ans;
    }
};