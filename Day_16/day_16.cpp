class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int res = 0;
        
        if (n % 2 != 0) {
            for (int num : nums2) {
                res ^= num;
            }
        }
        
        int m = nums2.size();
        if (m % 2 != 0) {
            for (int num : nums1) {
                res ^= num;
            }
        }
        
        return res;
    }
};
