class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allZero = true;
        int resultXOR = 0;
        for(int i=0;i<n;i++){
            resultXOR = resultXOR ^ nums[i];
            if(resultXOR != 0){
                allZero = false;
            }
        }
        if(allZero) return 0;
        return (resultXOR == 0) ? n-1 : n;
    }
};