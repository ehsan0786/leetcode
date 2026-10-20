class Solution {
public:
    typedef pair<int,int> p;
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

    // bool isSafe(int new_i,int new_j,int m,int n,vector<vector<int>>& grid){
    //     return (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1);
    // }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<p> que;
        int freshCount = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    que.push({i,j}); //source --> st
                }else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0; // all rotten -> already

        auto isSafe = [&](int new_i,int new_j){
            return (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1);
        };

        int time = 0; // levels

        while(!que.empty()){
            int size = que.size();
            while(size!=0){
                size--;
                p curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(isSafe(new_i,new_j)){
                        grid[new_i][new_j] = 2;
                        que.push({new_i,new_j});
                        freshCount--;
                    }
                }
            }
            time++;

        }

        return freshCount == 0 ? (time-1) : -1;


    }
};