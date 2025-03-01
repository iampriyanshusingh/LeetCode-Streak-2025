class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            //Apply operations and maintain non-zero operations on the left side
            int n=nums.size();
            int non_zero_idx=0;
    
            for(int i=0;i<n;++i){
                if(i<n-1 and nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
                if(nums[i]!=0)
                    swap(nums[i],nums[non_zero_idx++]);
            }
            return nums;
        }
    };