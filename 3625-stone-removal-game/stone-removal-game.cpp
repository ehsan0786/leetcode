class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10; // intially alice taken 10 steps 
        int steps = 0;

        while(n>=take){
            n-=take;
            take--;
            steps++;
        }
        return steps%2==1;
    }
};
