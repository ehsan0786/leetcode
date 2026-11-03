class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int moves = 0;
        for(auto x:nums){
            moves += maxi - x;
        }
        return moves;
    }
};