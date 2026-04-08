#include <vector>
#include <unordered_set>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int eucledianDistance(int x, int y) {
        return x * x + y * y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        int ans = 0, movedOffOrigin = 0;
        pair<int, int> pos = { 0,0 };
        for (auto i : obstacles)
            st.insert({ i[0], i[1] });
        vector<vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int currentDirection = 0;
        for (int i : commands) {
            if (i == -1) {
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (i == -2)
            {
                currentDirection = currentDirection - 1;
                if (currentDirection < 0)
                    currentDirection = 3;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                int x = dir[currentDirection][0];
                int y = dir[currentDirection][1];
                if (st.find({ pos.first + x, pos.second + y }) == st.end()) {
                    pos = { pos.first + x, pos.second + y };
                    ans = max(ans, eucledianDistance(pos.first, pos.second));
                }
            }
        }
        return ans;
    }
};
