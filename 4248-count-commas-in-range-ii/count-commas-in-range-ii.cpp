#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll st = 1000;
        while(st <= n){
            result += n-st+1;
            st *= 1000;
        }
        return result;
    }
};