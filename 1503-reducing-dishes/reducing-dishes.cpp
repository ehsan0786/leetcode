class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.rbegin(),satisfaction.rend());

        int preSum = 0;
        int ans = 0;
        for(auto &x : satisfaction){
            preSum += x;
            if(preSum>0) ans += preSum;
            else break;
        }
        return ans;
    }
};