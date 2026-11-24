class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_length = 0;

        for (int i = 0; i < n; i++) {
            long long prd = 1;
            int GCD = 0;
            long long LCM = 1;

            for (int j = i; j < n; j++) {
                prd *= nums[j];
                GCD = gcd(GCD, nums[j]);
                LCM = lcm(LCM, nums[j]);
                if (prd > LCM * GCD) {
                    break;
                }
                if (prd == LCM * GCD) {
                    max_length = max(max_length, j - i + 1);
                }
            }
        }

        return max_length;
    }
};
