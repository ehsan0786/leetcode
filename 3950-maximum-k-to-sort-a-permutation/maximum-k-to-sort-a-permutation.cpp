class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        //"1111111" (all bits set)
        int K = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                K = (K & nums[i]);
            }
        }

        return K == -1 ? 0 : K;

    }
};