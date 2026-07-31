#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        
        int count = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                vec.push_back({nums[i], count});
                count = 1;
            } else {
                count++;
            }
        }
        
        sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i][0]);
        }
        
        return result;
    }
};