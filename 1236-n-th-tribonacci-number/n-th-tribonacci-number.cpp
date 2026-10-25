class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) return n;
        if(n == 2) return 1;
        int a = 0,b=1,c=1;
        int temp = 0;
        for(int i=3;i<=n;i++){
            temp = a+b+c;
            a = b;
            b = c;
            c = temp;
        }
        return temp;
    }
};