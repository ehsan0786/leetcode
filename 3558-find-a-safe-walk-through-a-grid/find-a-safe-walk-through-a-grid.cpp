class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        deque<pair<int,int>> dq;
        result[0][0] = grid[0][0];
        dq.push_front({0,0}); // st. from source

        while(!dq.empty()){
            auto[r,c] = dq.front();
            dq.pop_front();

            for(auto &dir : directions){
                int r_ = r+dir[0];
                int c_ = c+dir[1];

                if(r_ >= 0 && r_ < m && c_ >= 0 && c_ < n){
                    if(result[r_][c_] > result[r][c] + grid[r_][c_]){
                        result[r_][c_] = result[r][c] + grid[r_][c_];
                        
                        if(grid[r_][c_] == 0){
                            dq.push_front({r_,c_});
                        }else{
                            dq.push_back({r_,c_});
                        }
                    }
                }
            }

        }

        int x  = result[m-1][n-1];
        return health-x >= 1;


    }
};