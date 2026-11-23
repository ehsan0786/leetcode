class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &x:nums){
            mp[x]++;
        }

        vector<int>ans;
        for(auto &y:mp){
            if(y.second == 2){
                ans.push_back(y.first);
            }
        }
        return ans;
    }
};