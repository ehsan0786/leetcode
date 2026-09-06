class Solution {
public:
vector<vector<int>>dp;
     int recursion(string &s,string &t,int i,int j){
          if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
      
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,not_take;
          if(s[i]==t[j]){
            take=recursion(s,t,i+1,j+1);
          }
          not_take=recursion(s,t,i+1,j);
      
      return dp[i][j]=take+not_take;
     };
    int numDistinct(string s, string t) {
        dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        return recursion(s,t,0,0);
    }
};