
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, curr_streak = 0;

        for (auto &num : nums) {
            if (num == 0) {
                curr_streak++;
            }else {
                cnt += curr_streak * (curr_streak + 1) / 2;
                curr_streak = 0;
            }
        }

        // Handle the remaining zero streak
        cnt += curr_streak * (curr_streak + 1) / 2;

        return cnt;
    }
};
