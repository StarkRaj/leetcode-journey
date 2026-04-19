#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int posInJ = lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]) - nums2.rbegin();
            int j = nums2.size() - posInJ - 1;

            if (i < j)
                ans = max(ans, j - i);
        }
        return ans;
    }
};
