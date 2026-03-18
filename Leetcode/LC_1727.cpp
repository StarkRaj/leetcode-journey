#include<vector>
#include <algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> consecutiveColumnCount;
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    consecutiveColumnCount = matrix[i];
                }
                else {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = matrix[i - 1][j] + 1;
                    }
                    consecutiveColumnCount.push_back(matrix[i][j]);
                }
            }
            sort(consecutiveColumnCount.begin(), consecutiveColumnCount.end(), greater<>());
            for (int k = 0; k < consecutiveColumnCount.size(); k++)
                ans = max(ans, (k + 1) * consecutiveColumnCount[k]);
        }
        return ans;
    }
};