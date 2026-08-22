class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    bool isSafe(int x,int y,int m,int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m==0 || n==0 || grid[0][0] != 0) return -1;

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        queue<P> que;

        que.push({0,{0,0}});
        result[0][0] = 0;

        while(!que.empty()){
            int d = que.front().first;
            pair<int,int> node = que.front().second;
            int x = node.first;
            int y = node.second;
            que.pop();

            for(auto &dir : directions){
                int x_ = x+dir[0];
                int y_ = y+dir[1];
                
                int dist = 1;
                if(isSafe(x_,y_,m,n) && grid[x_][y_]==0 && d+dist < result[x_][y_]){
                    que.push({d+dist,{x_,y_}});
                    // grid[x_][y_] = 1;
                    result[x_][y_] = d+dist;
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX) return -1;
        return result[m-1][n-1]+1;
    }
};