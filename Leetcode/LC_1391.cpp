#include <vector>
#include<unordered_map>.
#include<queue>
using namespace std;

struct cell {
    int currentX, currentY;
    int isVis = 0;
    int pipeType = 0;
};

class Solution {
public:
    unordered_map<int, vector<pair<int, int> > >mp;
    queue<cell> q;
    void initializeMap() {
        mp[1] = { {0,-1}, {0,1} };
        mp[2] = { {-1, 0}, {1, 0} };
        mp[3] = { {0,-1}, {1, 0} };
        mp[4] = { {1,0}, {0,1} };
        mp[5] = { {0,-1},{-1,0} };
        mp[6] = { {-1, 0},{0,1} };
    }

    bool isInside(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        initializeMap();
        vector<vector<cell>> cellMapping(m, vector<cell>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cellMapping[i][j] = cell({ i, j, 0, grid[i][j]});
            }
        }
        queue<pair<int, int> > q;
        q.push({ 0,0 });
        cellMapping[0][0].isVis = 1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front.first == m - 1 && front.second == n - 1) {
                return true;
            }
            cell currentCell = cellMapping[front.first][front.second];
            int currentPipeType = currentCell.pipeType;

            for (auto dir : mp[currentPipeType]) {
                pair<int, int> nextPipe = { currentCell.currentX + dir.first,
                    currentCell.currentY + dir.second
                };
                if (isInside(nextPipe.first, nextPipe.second, m, n) && !cellMapping[nextPipe.first][nextPipe.second].isVis)
                    for (auto prevDir : mp[cellMapping[nextPipe.first][nextPipe.second].pipeType]) {
                        if(nextPipe.first + prevDir.first == currentCell.currentX && nextPipe.second + prevDir.second == currentCell.currentY){
                            cellMapping[nextPipe.first][nextPipe.second].isVis = 1;
                            q.push(nextPipe);
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> grid = {{1,1,2}};
    return s.hasValidPath(grid);
}