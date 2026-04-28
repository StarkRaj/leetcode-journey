#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (int i = 0; i < grid.size();i++) {
            for (int j = 0;j < grid[0].size();j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int median = v[v.size() / 2];
        int ans = 0;
        for (auto i : v) {
            if (i % x != median % x)
                return -1;
            ans += abs(median - i) / x;
        }
        return ans;
    }
};