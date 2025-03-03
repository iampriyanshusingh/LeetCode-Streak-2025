class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int lCount = 0, gCount = 0, pCount = 0;
            
            for (int num : nums) {
                if (num < pivot) {
                    lCount++;
                } else if (num > pivot) {
                    gCount++;
                } else {
                    pCount++;
                }
            }
            
            int i = 0, j = lCount, k = lCount + pCount;
            vector<int> res(nums.size());
            
            for (int num : nums) {
                if (num < pivot) {
                    res[i++] = num;
                } else if (num > pivot) {
                    res[k++] = num;
                } else {
                    res[j++] = num;
                }
            }
            
            return res;
        }
    };