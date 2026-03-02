#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeroesCount(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                trailingZeroesCount[i]++;
            }
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int req = n - i - 1;
            int j = i;
            while (j < n && trailingZeroesCount[j] < req)
                j++;
            if (j == n)
                return -1;
            while (j > i) {
                swap(trailingZeroesCount[j], trailingZeroesCount[j - 1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};


/*
Intuition
To make the grid valid, every row i must have at least(n - i - 1) trailing zeros.Because:
Row 0 → needs n - 1 zeros
Row 1 → needs n - 2 zeros
Row 2 → needs n - 3 zeros
...
Last row → needs 0 zeros
So instead of swapping the whole grid, we:
Count trailing zeros in each row.
Try to place a valid row at each position.
If a valid row is below, bring it up using adjacent swaps.
Count swaps.
If no row satisfies requirement → return -1.
*/