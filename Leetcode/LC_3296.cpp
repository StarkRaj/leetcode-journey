#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1, high = 1e16;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long reducedHeight = 0;
            long long totalTime = 0;
            for (int i : workerTimes) {
                long long c = (mid * 2) / i;
                long long root1 = (-1 + sqrt(1 + 4 * c)) / 2;
                long long root2 = (-1 - sqrt(1 + 4 * c)) / 2;
                long long positiveRoot = (root1 >= 0) ? ceil(root1) : ceil(root2);
                reducedHeight += positiveRoot;
            }
            if (reducedHeight >= mountainHeight) {
                high = mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

//int main() {
//    Solution s;
//    vector<int> v = { 4,2,3,2 };
//    cout << s.minNumberOfSeconds(10, v);
//}