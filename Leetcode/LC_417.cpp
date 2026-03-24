#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    vector<vector<int> > dir = { {0,1}, {1,0}, {0,-1}, {-1, 0} };

    bool isInside(int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }

    struct Node {
        int x; int y;
    };

    stack<Node> st;
    vector<vector<int> > dp;
    vector<vector<int> > ans;

    void maxItcanFlow(int &m, int &n, vector<vector<int>>& heights, queue<Node> &q, bool isFromAtlantic) {
        vector<vector<int>>vis(m, vector<int>(n, 0));
        while (!q.empty()) {
            Node currentNode = q.front();
            q.pop();
            if (vis[currentNode.x][currentNode.y])
                continue;
            vis[currentNode.x][currentNode.y] = 1;
            if(!isFromAtlantic)
                dp[currentNode.x][currentNode.y] = 1;
            if (isFromAtlantic) {
                if (dp[currentNode.x][currentNode.y] == 1)
                    ans.push_back({ currentNode.x, currentNode.y });
            }
            for (auto d : dir) {
                int newX = currentNode.x + d[0];
                int newY = currentNode.y + d[1];
                if (isInside(newX, newY, m, n) && !vis[newX][newY] && heights[newX][newY] >= heights[currentNode.x][currentNode.y]) {
                    q.push({ newX, newY });
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ans.clear();
        int m = heights.size();
        int n = heights[0].size();
        queue<Node> q;
        dp.assign(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            q.push({ 0,i });
        for (int i = 1; i < m; i++)
            q.push({ i,0 });
        maxItcanFlow(m, n, heights, q, false);
        for (int i = 0; i < m; i++)
            q.push({ i,n-1 });
        for (int i = 0; i < n-1; i++)
            q.push({ m-1, i});
        maxItcanFlow(m, n, heights, q, true);
        return ans;
    }
};

//int main() {
//    vector<vector<int> > v = {
//        {1, 2, 2, 3, 5},
//        {3, 2, 3, 4, 4},
//        {2, 4, 5, 3, 1},
//        {6, 7, 1, 4, 5},
//        {5, 1, 1, 2, 4}
//    };
//
//    Solution sol;
//    auto result = sol.pacificAtlantic(v);
//    for (const auto& cell : result) {
//        cout << "[" << cell[0] << "," << cell[1] << "]\n";
//    }
//
//    return 0;
//}