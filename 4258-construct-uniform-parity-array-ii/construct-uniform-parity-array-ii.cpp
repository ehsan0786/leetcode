class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallOdd = INT_MAX;
        for(auto &x:nums1){
            if(x%2==1){
                smallOdd = min(smallOdd,x);
            }
        }
        if(smallOdd==INT_MAX) return true; //all ele are even
        for(auto &num : nums1){
            if(num%2 == 0 && num-smallOdd < 1){
                return false;
            }
        }
        return true;
    }
};