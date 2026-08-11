class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int seq_sum = nums[0];
        for(int j=1;j<nums.size();j++){
            if(nums[j]==nums[j-1]+1){
                seq_sum += nums[j];
            }else break;
        }
        while(st.count(seq_sum)){
            seq_sum++;
        }
        return seq_sum;
    }
};