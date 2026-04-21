#include <vector>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void dfs(set<string>& connectedMailsAndUsers, int node, vector<int>& vis, unordered_map<int, vector<int> >& graph, vector<vector<string>>& accounts) {
        for (int i = 1; i < accounts[node].size(); i++)
            connectedMailsAndUsers.insert(accounts[node][i]);
        vis[node] = 1;
        for (auto i : graph[node]) {
            if (!vis[i])
                dfs(connectedMailsAndUsers, i, vis, graph, accounts);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, vector<int> >graph;
        unordered_map<string, int> nameEmailMapping;
        for (int i = 0; i < accounts.size(); i++) {
            graph[i] = {};
            for (int j = 1; j < accounts[i].size(); j++) {
                if (nameEmailMapping.find(accounts[i][j]) != nameEmailMapping.end()) {
                    int user = nameEmailMapping[accounts[i][j]];
                    if (user != i) {
                        graph[i].push_back(user);
                        graph[user].push_back(i);
                    }
                }
                nameEmailMapping[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> ans;
        
        vector<int> vis(accounts.size(), 0);
        for (int i = 0; i < accounts.size(); i++) {
            if (!vis[i]) {
                set<string> connectedMailsAndUsers;
                dfs(connectedMailsAndUsers, i, vis, graph, accounts);
                vector<string> temp = { accounts[i][0] };
                for (auto i : connectedMailsAndUsers)
                    temp.push_back(i);
                ans.push_back(temp);
            }
                
        }
        return ans;
    }
};

//int main() {
//    Solution s = Solution();
//    vector<vector<string>> accounts = {
//    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
//    {"John", "johnsmith@mail.com", "john00@mail.com"},
//    {"Mary", "mary@mail.com"},
//    {"John", "johnnybravo@mail.com"}
//    };
//    vector<vector<string>> ans = s.accountsMerge(accounts);
//}