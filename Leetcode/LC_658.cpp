#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        while (k--) {
            if (r >= n || l >= 0 && (x - arr[l]) <= (arr[r] - x))
                l--;
            else
                r++;
        }
        return vector<int>(begin(arr) + l + 1, begin(arr) + r);
    }
};