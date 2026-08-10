class Solution {
public:
    vector<int> t;
    bool solve(int n){
        if(n==0){
            return false;
        }
        if(t[n] != -1){
            return t[n] == 1 ? true: false;
        }
        for(int k=1;k*k<=n;k++){
            if(!solve(n-k*k)){ //call for bob // false - bob lost it alice win
                return t[n]=true;
            }
        } 
        return t[n]=false; //Alice lose
    }
    bool winnerSquareGame(int n) {
        t.assign(n+1,-1);
        return solve(n); //Alice ke liye call hai ye.if its true ,alice wins ,else alice looses
    }
};