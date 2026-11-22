class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int prd = 1;
            for(int j=i;j<n;j++){
                prd *= nums[j];
                if(prd < k){
                    ans++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};