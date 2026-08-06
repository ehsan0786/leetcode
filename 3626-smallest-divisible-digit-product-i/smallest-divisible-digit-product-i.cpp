class Solution {
public:
    int prod(int num){
        int ans = 1;
        while(num > 0){
            ans *= (num % 10);
            num /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i= n; ; i++){
            if(prod(i)%t==0){
                return n;
            }
            n++;
        }
    }
};