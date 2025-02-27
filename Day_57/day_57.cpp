class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int min_point = 0;
            int max_point = 0;
            int prefix_sum = 0;
            for(int ele: nums){
                prefix_sum += ele;
    
                min_point = min(min_point,prefix_sum);
                max_point = max(max_point,prefix_sum);
            }
            return max_point - min_point;
        }
    };

    //mistakes happen