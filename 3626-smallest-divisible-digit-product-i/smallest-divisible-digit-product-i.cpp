class Solution {
public:
    int digitProduct(int num){
        int prod = 1;
        while(num){
            prod *= (num%10);
            if(prod==0){ //early return 
                return 0;
            }
            num /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int num=n;num<=num+10;num++){
            if(digitProduct(num)%t==0){
                return num;
            }
        }
        return -1;
    }
};