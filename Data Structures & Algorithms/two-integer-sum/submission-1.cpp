class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> duplicate = nums;
        sort(duplicate.begin(), duplicate.end());
        
        int i = 0;
        int j = nums.size() - 1;
        int val1 = 0, val2 = 0;
        
        while (i < j) {
            if (duplicate[i] + duplicate[j] > target) {
                j--;
            } else if (duplicate[i] + duplicate[j] < target) {
                i++;
            } else {
                val1 = duplicate[i];
                val2 = duplicate[j];
                break;
            }
        }
        
        vector<int> ans;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == val1 || nums[k] == val2) {
                ans.push_back(k);
            }
        }
        
        return ans;
    }
};