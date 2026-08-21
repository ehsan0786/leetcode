class Solution {
public:
long long lcm(long long  a, long long  b){
    return (a * b ) / gcd(a,b);
}
  int n;
  long long count(long long mid,vector<int>& coins){
    long long a = 0; 
    for(int i=1;i < (1 << n); i++){
        long long l = 1;
        long long bits = 0;
        bool toolarge = false;

        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                bits++;
                l = lcm(l , coins[j]);
            }
            if(l > mid){toolarge = true;break;}
            
            
        }
        if(toolarge)continue;
        long long cur = mid / l;
        if(bits % 2 == 1){
            a  += cur;
        }
        else a -= cur;
    }
    return a;
  }
    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        long long l = 1;
        long long r = 1ll * (*min_element(coins.begin(),coins.end())) * k;
        while( l < r){
            long long mid = l + (r-l)/2;
            if(count(mid,coins) >= k){
                r= mid;
            }
            else l = mid+1;
        }
        return l;
    }
};