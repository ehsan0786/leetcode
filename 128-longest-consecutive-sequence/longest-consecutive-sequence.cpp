class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi = 0;

        for(auto &x:st){
            if(!st.count(x-1)){
                int curr = x;
                int length = 1;
                while(st.count(curr+1)){
                    curr += 1;
                    length += 1;
                }
                maxi = max(maxi,length);
            }
        }
        return maxi;
    }
};