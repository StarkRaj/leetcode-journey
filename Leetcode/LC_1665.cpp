#include<vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    struct compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[1]-a[0] == b[1]-b[0])
                return a[1] > b[1];
            return a[1]-a[0] > b[1]-b[0];
        }
    };

    bool canFinish(vector<vector<int>>& tasks, int energy) {
        for (auto i : tasks) {
            if (energy < i[1])
                return false;
            energy -= i[0];
        }
        if (energy < 0)
            return false;
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), compare());
        int low = 0, high = 0;
        for (int i = 0; i < n;i++) {
            high += tasks[i][1];
            low = max(low, tasks[i][1]);
        }
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(tasks, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

//int main() {
//    vector<vector<int>> v = {
//    {1, 3},
//    {2, 4},
//    {10, 11},
//    {10, 12},
//    {8, 9}
//    };
//    return Solution().minimumEffort(v);
//}