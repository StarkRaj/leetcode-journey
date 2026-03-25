#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<long long int> topToBottom, leftToRight;
        vector<long long int> bottomToTop(m, 0), rightToLeft(n, 0);
        long long int sum = 0;
        // for horizontal cut
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            topToBottom.push_back(sum);
        }
        sum = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            bottomToTop[i] = sum;
        }
        if (m > 1) {
            for (int i = 0; i < m - 1; i++) {
                if (topToBottom[i] == bottomToTop[i + 1])
                    return true;
            }
        }

        // for vertical cut
        sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[j][i];
            }
            leftToRight.push_back(sum);
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                sum += grid[j][i];
            }
            rightToLeft[i] = sum;
        }
        if (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                if (leftToRight[i] == rightToLeft[i + 1])
                    return true;
            }
        }
        return false;
    }
};
