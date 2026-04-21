#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int i) {
        if (parent[i] == i)
            return i;
        return findParent(parent[i]);
    }

    void doUnion(int node1, int node2) {
        int x = findParent(node1);
        int y = findParent(node2);
        if (x == y)
            return;
        if (rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x]++;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int ans = 0;
        parent.resize(source.size());
        rank.resize(source.size(), 0);
        for (int i = 0; i < source.size(); i++)
            parent[i] = i;

        for (auto i : allowedSwaps) {
            doUnion(i[0], i[1]);
        }
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < source.size(); i++) {
            mp[findParent(i)][source[i]]++;
        }
        for (int i = 0; i < target.size();i++) {
            int cluster = findParent(i);
            if (mp[cluster].find(target[i]) == mp[cluster].end())
                ans++;
            else {
                mp[cluster][target[i]]--;
                if (mp[cluster][target[i]] < 0)
                    ans++;
            }
        }
        return ans;
    }
};

//int main() {
//    vector<int> src = { 5,1,2,4,3 };
//    vector<int> target = { 1,5,4,2,3 };
//    vector<vector<int> > allowedSnaps = { {0,4}, {4,2}, {1,3}, {1,4} };
//    Solution s = Solution();
//    return s.minimumHammingDistance(src, target, allowedSnaps);
//}