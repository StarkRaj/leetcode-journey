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
        for (int i = 0;i < n; i++) {
            int elapsedTime = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                if (waterStartTime[j] <= elapsedTime) {
                    ans = min(ans, elapsedTime + waterDuration[j]);
                }
                else {
                    ans = min(ans, waterStartTime[j] + waterDuration[j]);
                }
            }
        }
        for (int i = 0;i < m; i++) {
            int elapsedTime = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n; j++) {
                if (landStartTime[j] <= elapsedTime) {
                    ans = min(ans, elapsedTime + landDuration[j]);
                }
                else {
                    ans = min(ans, landStartTime[j] + landDuration[j]);
                }
            }
        }
        return ans;
    }
};