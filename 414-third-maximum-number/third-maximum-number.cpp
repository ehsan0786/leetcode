class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int n = st.size();
        vector<int> vec(st.begin(),st.end());
        sort(vec.rbegin(),vec.rend());
        if(n<3) return vec[0];
        return vec[2];
    }
};