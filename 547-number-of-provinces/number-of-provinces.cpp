class Solution {
public:
    int n;
    void BFS(vector<vector<int>>& isConnected,int u,vector<bool> &visited){
        queue<int> que;
        visited[u]=true;
        que.push(u);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int v=0;v<n;v++){
                if(!visited[v] && isConnected[u][v]==1){
                    BFS(isConnected,v,visited);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(isConnected,i,visited);
                cnt++;
            }
        }
        return cnt;
    }
};