#include <vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char> > newBoxGrid(n, vector<char>(m, '.'));
        for (int i = m - 1; i >= 0; i--) {
            queue<pair<int, int> > q;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    newBoxGrid[j][m - 1 - i] = '*';
                    while (!q.empty())
                        q.pop();
                }
                else if (boxGrid[i][j] == '.')
                    q.push({ j,m - 1 - i });
                else {
                    if (!q.empty()) {
                        auto cell = q.front();
                        q.pop();
                        newBoxGrid[cell.first][cell.second] = '#';
                        q.push({ j,m - 1 - i });
                    }
                    else {
                        newBoxGrid[j][m - 1 - i] = '#';
                    }
                }
            }
        }
        return newBoxGrid;
    }
};