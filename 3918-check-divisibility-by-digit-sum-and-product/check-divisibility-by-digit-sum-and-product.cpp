class Solution {
public:
    int sum(int n){
       int x = 0;
        while(n > 0){
            int last_dig = n%10;
            x += last_dig;
            n /= 10;
        }
        return x;
    }

    int product(int n){
       int x = 1;
       while(n > 0){
         int last_dig = n%10;
            x *= last_dig;
            n /= 10;
       }
       return x;
    }

    bool checkDivisibility(int n) {
        int dig_sum = sum(n);
        int dig_prod = product(n);
        return (n % (dig_sum + dig_prod) == 0);
    }
};