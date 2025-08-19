//Sol^n 1
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
                ans+=count;
            }else{
                count=0;
            }
        }
        return ans;
    }
};

//Sol^n 2
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
            }else{
                ans+=(count*(count+1))/2;
                count=0;
            }
        }
        ans+=(count*(count+1))/2;
        return ans;
    }
};