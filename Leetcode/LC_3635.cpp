#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterDuration.size();

        int shortestLandTime = INT_MAX;
        for (int i = 0;i < n; i++) {
            shortestLandTime = min(shortestLandTime, landStartTime[i] + landDuration[i]);
        }
        for (int j = 0;j < m; j++) {
            if (waterStartTime[j] <= shortestLandTime) {
                ans = min(ans, shortestLandTime + waterDuration[j]);
            }
            else {
                ans = min(ans, waterStartTime[j] + waterDuration[j]);
            }
        }
        
        int shortestWaterTime = INT_MAX;
        for (int i = 0;i < m; i++) {
            shortestWaterTime = min(shortestWaterTime, waterStartTime[i] + waterDuration[i]);
        }
        for (int j = 0;j < n; j++) {
            if (landStartTime[j] <= shortestWaterTime) {
                ans = min(ans, shortestWaterTime + landDuration[j]);
            }
            else {
                ans = min(ans, landStartTime[j] + landDuration[j]);
            }
        }
        
        return ans;
    }
};