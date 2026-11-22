class Solution {
public:
    int at_most_k(vector<int>& nums, int k){
        if(k<0) return 0; // less than zero odd count not possible

        int odd_cnt = 0;
        int ans = 0;
        int i = 0;//left

        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0) odd_cnt++;
            while(odd_cnt > k){
                if(nums[i]%2!=0){
                    odd_cnt -= 1;
                }
                i++;
            }
            ans +=j-i+1;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return at_most_k(nums,k) - at_most_k(nums,k-1);
    }
};