class Solution {
public:
    bool threeFibonacciSum(int n) {
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        while(true){
            int curr_sum = prev3+prev2+prev1;    
            
            if(curr_sum == n) return true;
            if(curr_sum > n) return false;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = prev3 + prev2;
    
        }
    }
};