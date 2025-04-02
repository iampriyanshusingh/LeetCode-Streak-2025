class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxResult = 0;
            int maxNum = 0;    // Tracks the maximum nums[i]
            int maxDiff = 0;   // Tracks the maximum (nums[i] - nums[j])
    
            for (const int num : nums) {
                maxResult = max(maxResult, static_cast<long long>(maxDiff) * num);
                maxDiff = max(maxDiff, maxNum - num);
                maxNum = max(maxNum, num);
            }
    
            return maxResult;
        }
    };