class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int moves = 0;

        for(int i=0;i<n/2;i++){
            moves += abs(nums[i]-nums[n/2]);
            moves += abs(nums[n-i-1]-nums[n/2]);
        }
        return moves;
    }
};


// nth_element() → Places only the required element at its correct sorted position.