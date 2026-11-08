class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int total = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            total += nums[j];
            while (i <= j && total >= target){
                ans = min(ans,j-i+1);
                total -= nums[i];
                i++;
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};