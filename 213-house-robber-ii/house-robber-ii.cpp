
class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {

        if (ind == 0) return nums[ind];
        if (ind < 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind - 2, nums, dp);
        int not_pick = 0 + solve(ind - 1, nums, dp);

        return dp[ind] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int x = solve(temp1.size() - 1, temp1, dp1);
        int y = solve(temp2.size() - 1, temp2, dp2);

        return max(x, y);
    }
};
