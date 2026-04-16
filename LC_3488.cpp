#include<vector>
#include <unordered_map>
using namespace std;

struct Node {
    int pos, left, right;
};

class Solution {
public:
    int binarySearch(vector<Node>& v, int target) {
        int n = v.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (v[mid].pos == target)
                return min(v[mid].left, v[mid].right);
            if (v[mid].pos < target)
                low = mid + 1;
            else
                high = mid;
        }
        return min(v[low].left, v[low].right);
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<Node> > mp;
        for (int i = 0; i < n;i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].push_back({ i, -1, -1 });
            }
            else {
                Node lastElement = mp[nums[i]].back();
                int leftDist = i - lastElement.pos;
                mp[nums[i]].back().right = leftDist;
                mp[nums[i]].push_back({ i, leftDist, -1 });
            }
        }
        for (auto& i : mp) {
            if (i.second.size() > 1) {
                int circularDist = (n - (i.second.back().pos - i.second[0].pos));

                i.second[0].left = circularDist;
                i.second.back().right = circularDist;
            }
        }
        vector<int> ans;
        for (auto i : queries) {
            if (mp[nums[i]].size() == 1)
                ans.push_back(-1);
            else {
                ans.push_back(binarySearch(mp[nums[i]], i));
            }
        }
        return ans;
    }
};

//int main() {
//    vector<int> v = { 2,10,20,20,20 };
//    vector<int> q = { 1,4,2 };
//    Solution s = Solution();
//    vector<int> ans = s.solveQueries(v, q);
//    return 0;
//}