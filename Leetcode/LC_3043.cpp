#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for (auto i : arr1) {
            string nm = to_string(i);
            string temp = "";
            for (auto j : nm) {
                temp += j;
                st.insert(temp);
            }
        }
        int ans = 0;
        for (auto i : arr2) {
            string nm = to_string(i);
            string temp = "";
            for (auto j : nm) {
                temp += string(1, j);
                if (st.find(temp) != st.end()) {
                    int wordLength = temp.size();
                    ans = max(ans, wordLength);
                }
                else
                    break;
            }
        }
        return ans;
    }
};

//int main() {
//    vector<int> n1 = { 1,10,100 };
//    vector<int> n2 = { 1000 };
//    return Solution().longestCommonPrefix(n1, n2);
//}