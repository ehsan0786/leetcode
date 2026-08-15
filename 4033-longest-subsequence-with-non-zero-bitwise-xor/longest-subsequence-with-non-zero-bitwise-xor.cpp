class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int zero_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero_count++;
             x=x^nums[i];
        }
        if(x) return nums.size();
        else if(zero_count==nums.size()) return 0;
        else return nums.size()-1;
    }
};