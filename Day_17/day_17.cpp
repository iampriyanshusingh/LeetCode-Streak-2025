class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (int val : derived) {
            res ^= val; 
        }
        return (res == 0);
    }
};
