#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct Node {
        int sum;
        bool hasX;
    };

    bool isCurrentValueX(char ch) {
        if (ch == 'X')
            return true;
        return false;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        unordered_map<char, int> mp;
        mp['X'] = 1;
        mp['Y'] = -1;
        mp['.'] = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<Node> > prefixSum(m + 1, vector<Node>(n + 1, { 0,false }));
        int count = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++){
                int sum = prefixSum[i - 1][j].sum + prefixSum[i][j - 1].sum - prefixSum[i - 1][j - 1].sum + mp[grid[i - 1][j - 1]];
                bool hasX = prefixSum[i - 1][j].hasX || prefixSum[i][j - 1].hasX || prefixSum[i - 1][j - 1].hasX || isCurrentValueX(grid[i-1][j-1]);
                prefixSum[i][j] = { sum, hasX };
                if (sum == 0 && hasX)
                    count++;
            }
        }
        return count;
    }
};