class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        unordered_map<int,int> dp;
        for(auto &num:nums){
            dp[num+1]=dp[num]+1;
            dp[num]=dp[num-1]+1;
            
           ans=max({ans,dp[num],dp[num+1]});

        }

        return ans;
    }
};