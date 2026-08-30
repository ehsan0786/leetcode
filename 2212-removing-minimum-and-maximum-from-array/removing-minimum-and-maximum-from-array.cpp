class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int maxl=0,maxr=0,minl=0,minr=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==mini){
              minl=i+1;
               minr=nums.size()-i;
             }
             if(nums[i]==maxi){
                 maxl=i+1;
                 maxr=nums.size()-i;
             }
        }
       
        int ans1=max(minl,maxl);

        int ans2=max(minr,maxr);

        int ans3=min(minl+maxr,minr+maxl);

        return min({ans1,ans2,ans3});
    }
};