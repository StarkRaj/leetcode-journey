#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sum(m+1, vector<int>(n+1,0));
        int count = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + grid[i - 1][j - 1] - sum[i-1][j-1];
                if (sum[i][j] <= k)
                    count++;
            }
        }
        return count;

    }
};

int main() {
    vector<vector<int>> v = {{7, 2, 9}, { 1, 5, 0}, { 2, 6, 6 }};
    Solution s = Solution();
    int ans = s.countSubmatrices(v, 20);
}