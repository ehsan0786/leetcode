class Solution {
public:
    int n;
    int t[100001];
    int solve(int i,vector<int> &prefixSum){
        if(i==n-1) return prefixSum[n-1];
        if(t[i] != -1) return t[i];
        int take = prefixSum[i] - solve(i+1,prefixSum);
        int skip = solve(i+1,prefixSum);
        return t[i] = max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        memset(t,-1,sizeof(t));
        vector<int> prefixSum(n,0);
        prefixSum[0] = stones[0];

        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }
        vector<int> t(n,0);
        //base : if(i==n-1) return prefixsum[n-1];
        t[n-1] = prefixSum[n-1];

        for(int i=n-2;i>=1;i--){
            int take = prefixSum[i] - t[i+1];
            int skip = t[i+1];
            t[i] = max(take,skip);
        }
        return t[1]; // solve(1);
    }
};