class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right = 0, left = 0;
        for (int num : nums) {
            right += num;
        }
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                count++;
            }
        }
        return count;
    }
};
