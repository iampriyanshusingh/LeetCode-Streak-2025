class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> res;
            int p1=0;
            int p2=0;
            int m=nums1.size();
            int n=nums2.size();
    
            while(p1<m and p2<n){
                if(nums1[p1][0]==nums2[p2][0]){
                    res.push_back(nums1[p1]);
                    res.back()[1] += nums2[p2][1];
                    p1++;
                    p2++;
                }else if(nums1[p1][0]<nums2[p2][0]){
                    res.push_back(nums1[p1]);
                    p1++;
                }else{
                    res.push_back(nums2[p2]);
                    p2++;
                }
            }
            //Fill leftover from nums1
            while(p1<m){
                res.push_back(nums1[p1]);
                p1++;
            }
            //Fill leftover from nums2
            while(p2<n){
                res.push_back(nums2[p2]);
                p2++;
            }
            return res;
        }
    };