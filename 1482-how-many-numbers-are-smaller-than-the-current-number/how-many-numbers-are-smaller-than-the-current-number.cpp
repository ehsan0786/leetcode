class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(j!= i && nums[j]<nums[i]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans = nums;
//         unordered_map<int, int> mp;
//         sort(ans.begin(), ans.end());
//         for (int i = n - 1; i >= 0; i--) {
//             mp[ans[i]] = i;
//         }
//         for (int i = 0; i < n; i++) {
//             ans[i] = mp[nums[i]];
//         }
//         return ans;
//     }
// };