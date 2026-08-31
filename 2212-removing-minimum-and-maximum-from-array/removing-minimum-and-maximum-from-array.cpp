class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        int n = nums.size();
        int maxElIdx = 0,minElIdx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                minElIdx = i;
            }
             if(nums[i]==maxi){
                maxElIdx = i;
            }
        }
        int left = min(minElIdx,maxElIdx);
        int right = max(minElIdx,maxElIdx);
        return min({left+1+n-right,right+1,n-left});
    }
};