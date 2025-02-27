
//Approach-1: Greedy Simulation...TC: O(N^2 logM)...SC: O(N)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> values(arr.begin(),arr.end());
        
        int longest=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int a = arr[i];
                int b = arr[j];
                int fib_len = 2;
                while(values.count(a+b)>0){
                    int sum = a+b;
                    a = b;
                    b = sum;
                    fib_len++;
                }
                if(fib_len>2)
                    longest = max(longest,fib_len);
            }
        }
        return longest;
    }
};

//Approach-2: Binary Search...TC: O(N^2 logN)...SC: O(1)
class Solution {
    int fibChainLength(vector<int>& arr,int a,int b,int& n){
        int fib_idx = lower_bound(arr.begin(),arr.end(),a+b)-arr.begin();
        if(fib_idx<n and arr[fib_idx]==a+b)
            return 1 + fibChainLength(arr,b,a+b,n);
        return 0;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int longest=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int a=arr[i];
                int b=arr[j];
                int fib_len = fibChainLength(arr,a,b,n);
                if(fib_len>0)
                    longest = max(longest,2+fib_len);
            }
        }
        return longest;
    }
};

//Approach-3: Dynamic Programming...TC:O(N^2)...SC:O(N^2)
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size();
            vector<vector<int>> dp(n,vector<int>(n));
            //(Subproblem) dp[x][y]: Longest fib chain length ending at 'y' with 'x' being the previous item
    
            int longest=0;
            for(int sum=2;sum<n;++sum){
                int a=0;
                int b=sum-1;
                //Two-Sum approach
                while(a<b){
                    if(arr[a]+arr[b]<arr[sum])       a++;
                    else if(arr[a]+arr[b]>arr[sum])  b--;
                    else{
                        dp[b][sum] = 1+dp[a][b];
                        longest = max(longest,dp[b][sum]);
                        a++;
                        b--;
                    }
                }
            }
            return longest==0? 0 : 2+longest;
        }
    };
