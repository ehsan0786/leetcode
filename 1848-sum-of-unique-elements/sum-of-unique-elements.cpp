class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]++;
        }
        for(auto &y:mp){
            if(y.second == 1){
                sum += y.first;
            }
        }
        return sum;
    }
};