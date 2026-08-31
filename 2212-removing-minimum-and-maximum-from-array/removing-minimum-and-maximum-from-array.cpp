class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(nums.begin(),nums.end())-nums.begin();
        int maxElIdx = max_element(nums.begin(),nums.end())-nums.begin();

        int left= min(minElIdx,maxElIdx); //leftSide
        int right= max(minElIdx,maxElIdx); //rightSide

        return min({left+1+n-right,right+1,n-left});
        
    }
};