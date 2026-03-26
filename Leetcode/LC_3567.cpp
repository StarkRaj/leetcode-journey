#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > ans;
        for (int i = 0; i <= m - k; i++) {
            vector<int> rowWiseAns;
            for (int j = 0; j <= n - k; j++) {
                set<int> st;
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        st.insert(grid[i + x][j + y]);
                    }
                }
                if(st.size() <= 1)
                    rowWiseAns.push_back(0);
                else {
                    int minAbsoluteValue = INT_MAX;
                    auto prev = st.begin();
                    auto current = next(prev);
                    while (current != st.end()) {
                        minAbsoluteValue = min(minAbsoluteValue, abs(*current - *prev));
                        ++prev;
                        ++current;
                    }
                    rowWiseAns.push_back(minAbsoluteValue);
                }
            }
            ans.push_back(rowWiseAns);
        }
        return ans;
    }
};