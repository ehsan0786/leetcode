class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";
        int nines = sum/9;
        int remaining = sum%9;
        string ans(nines,'9');
        if(remaining > 0){
            ans.push_back(remaining+'0');
        }
        ans.append(num-ans.size(),'0');
        return ans;
    }
};